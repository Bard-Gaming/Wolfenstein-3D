#!/bin/env python3

import tkinter as tk
from tkinter import colorchooser, messagebox, filedialog
from dataclasses import dataclass
from typing import Literal
import argparse
import sys
import os
import random

# === Default Parameters ===
DEFAULT_TEXTURE = ""
DEFAULT_COLOR_HEX = "ffffffff"  # solid white


@dataclass
class MapCell:
    is_solid: bool
    texture: str
    color: int

    def to_bytes(self, byteorder: Literal["little", "big"] = "little") -> bytes:
        if not self.is_solid:
            return b'\x00'

        array = bytearray()

        # Type:
        array.extend(b'\x01')  # 1 for solid wall (we already know this cell is solid)

        # Texture:
        array.extend(self.texture.encode("ascii") + b'\x00')  # Add terminating null-byte

        # Color:
        array.extend(self.color.to_bytes(4, byteorder))

        return bytes(array)

    @classmethod
    def from_file(cls, file, byteorder: Literal["little", "big"] = "little") -> "MapCell":
        is_solid: bytes = file.read(1)
        if is_solid[0] == 0:
            return MapCell(False, "", int(DEFAULT_COLOR_HEX, 16))

        # Texture:
        texture_bytes = bytearray()
        char = file.read(1)
        while char[0] != 0:
            texture_bytes.extend(char)
            char = file.read(1)
        texture = texture_bytes.decode("ascii")

        # Color:
        color_bytes = file.read(4)
        color = int.from_bytes(color_bytes, byteorder)

        return cls(True, texture, color)


class Map:
    def __init__(self, width: int, height: int) -> None:
        self.width = width
        self.height = height
        self.cells = [
            [MapCell(False, "", int(DEFAULT_COLOR_HEX, 16)) for _ in range(width)]
            for _ in range(height)
        ]

    def to_bytes(self, byteorder: Literal["little", "big"] = "little") -> bytes:
        array = bytearray()

        # Dimensions:
        array.extend(self.width.to_bytes(4, byteorder))
        array.extend(self.height.to_bytes(4, byteorder))

        # Cell data:
        for cell in self:
            array.extend(cell.to_bytes(byteorder))

        return bytes(array)

    @classmethod
    def from_file(cls, file, byteorder: Literal["little", "big"] = "little") -> "Map":
        # Dimensions:
        width = int.from_bytes(file.read(4), byteorder)
        height = int.from_bytes(file.read(4), byteorder)

        map_data = cls(width, height)

        # Cells:
        for y in range(height):
            for x in range(width):
                map_data.cells[y][x] = MapCell.from_file(file, byteorder)

        return map_data

    def __getitem__(self, index: tuple) -> MapCell:
        if not isinstance(index, tuple) or len(index) != 2:
            raise TypeError("Map: index needs to be a 2D tuple.")

        return self.cells[index[1]][index[0]]

    def __setitem__(self, index: tuple, other: "MapCell"):
        if not isinstance(index, tuple) or len(index) != 2:
            raise TypeError("Map: index needs to be a 2D tuple.")
        if not isinstance(other, MapCell):
            raise TypeError("Map: item type needs to be of type MapCell.")

        self.cells[index[1]][index[0]] = other

    def __iter__(self) -> iter:
        for row in self.cells:
            for cell in row:
                yield cell

    def __repr__(self) -> str:
        return f"Map({self.width}, {self.height})"


class MapEditor(tk.Tk):
    def __init__(self, default_texture=DEFAULT_TEXTURE, default_color=int(DEFAULT_COLOR_HEX, 16)):
        super().__init__()
        self.title("Wolf3D Map Editor")
        self.geometry("1200x800")

        self.map = None

        # Config:
        self.default_texture = default_texture
        self.default_color = default_color
        self.cell_size = 20

        # App State:
        self.cell_ids = {}
        self.selected_x = None
        self.selected_y = None
        self.selection_overlay_id = None
        self.texture_display_color = {}

        self.setup_ui()

    @property
    def selected_cell(self) -> MapCell:
        return self.map[self.selected_x, self.selected_y]

    @selected_cell.setter
    def selected_cell(self, value: MapCell) -> None:
        if not isinstance(value, MapCell):
            raise TypeError("MapEditor: tried setting selected cell to a value that isn't of type MapCell")

        self.map[self.selected_x, self.selected_y] = value

    def setup_ui(self):
        self.grid_rowconfigure(1, weight=1)
        self.grid_columnconfigure(0, weight=1)

        dimension_frame = tk.Frame(self, padx=5, pady=5)
        dimension_frame.grid(row=0, column=0, sticky="w", columnspan=2)

        tk.Label(dimension_frame, text="Width:").pack(side="left")
        self.width_entry = tk.Entry(dimension_frame, width=5)
        self.width_entry.insert(0, "50")
        self.width_entry.pack(side="left")

        tk.Label(dimension_frame, text="Height:").pack(side="left")
        self.height_entry = tk.Entry(dimension_frame, width=5)
        self.height_entry.insert(0, "50")
        self.height_entry.pack(side="left")

        tk.Button(dimension_frame, text="Generate Grid", command=self.generate_grid).pack(side="left", padx=10)
        tk.Button(dimension_frame, text="Export Map", command=self.export_map).pack(side="left")

        canvas_container = tk.Frame(self)
        canvas_container.grid(row=1, column=0, sticky="nsew")

        self.canvas = tk.Canvas(canvas_container, bg="white")
        self.canvas.pack(side="left", fill="both", expand=True)

        self.vbar = tk.Scrollbar(canvas_container, orient="vertical", command=self.canvas.yview)
        self.vbar.pack(side="right", fill="y")
        self.canvas.config(yscrollcommand=self.vbar.set)
        self.canvas.bind("<Button-1>", self.on_canvas_click)

        self.hbar = tk.Scrollbar(self, orient="horizontal", command=self.canvas.xview)
        self.hbar.grid(row=2, column=0, sticky="we")
        self.canvas.config(xscrollcommand=self.hbar.set)

        self.panel = tk.Frame(self, padx=10, pady=10)
        self.panel.grid(row=1, column=1, sticky="n")

        tk.Label(self.panel, text="Texture:").pack()
        self.texture_entry = tk.Entry(self.panel)
        self.texture_entry.pack()

        tk.Label(self.panel, text="Color (hex):").pack()
        self.color_button = tk.Button(self.panel, text="Pick Color", command=self.pick_color)
        self.color_button.pack()
        self.color_hex = tk.Entry(self.panel)
        self.color_hex.pack()

        self.create_wall_button = tk.Button(self.panel, text="Create Wall", command=self.create_wall)
        self.create_wall_button.pack(pady=5)

        self.destroy_wall_button = tk.Button(self.panel, text="Destroy Wall", command=self.destroy_wall)
        self.destroy_wall_button.pack(pady=5)

    def generate_grid(self):
        try:
            width = int(self.width_entry.get())
            height = int(self.height_entry.get())
        except ValueError:
            messagebox.showerror("Invalid Input", "Width and Height must be integers.")
            return

        # Create blank map:
        self.map = Map(width, height)

        self.grid_width = width
        self.grid_height = height

        self.canvas.delete("all")
        self.cell_ids = {}
        self.selected_x = None
        self.selected_y = None

        total_width = width * self.cell_size
        total_height = height * self.cell_size
        self.canvas.config(scrollregion=(0, 0, total_width, total_height))

        for y in range(height):
            for x in range(width):
                x1 = x * self.cell_size
                y1 = y * self.cell_size
                x2 = x1 + self.cell_size
                y2 = y1 + self.cell_size
                rect_id = self.canvas.create_rectangle(x1, y1, x2, y2, fill="white", outline="black")
                self.cell_ids[x, y] = rect_id

    def update_cell_color(self, x, y):
        cell = self.map[x, y]
        if cell.is_solid:
            if cell.texture not in self.texture_display_color:
                self.texture_display_color[cell.texture] = random.randint(0, 0xffffffff)
            color = self.texture_display_color[cell.texture]
        else:
            color = int(DEFAULT_COLOR_HEX, 16)
        self.canvas.itemconfig(self.cell_ids[x, y], fill=f"#{(color >> 8) & 0xffffff:06x}")

    def on_canvas_click(self, event):
        if not hasattr(self, "grid_width") or not hasattr(self, "grid_height"):
            return

        canvas_x = self.canvas.canvasx(event.x)
        canvas_y = self.canvas.canvasy(event.y)
        x = int(canvas_x // self.cell_size)
        y = int(canvas_y // self.cell_size)

        if not (0 <= x < self.grid_width and 0 <= y < self.grid_height):
            return

        self.selected_x = x
        self.selected_y = y

        if self.selection_overlay_id:
            self.canvas.delete(self.selection_overlay_id)

        x1 = x * self.cell_size
        y1 = y * self.cell_size
        x2 = x1 + self.cell_size
        y2 = y1 + self.cell_size
        self.selection_overlay_id = self.canvas.create_rectangle(
            x1, y1, x2, y2, outline="black", fill="#aaaaaa", stipple="gray25"
        )

        self.load_cell_to_editor()

    def load_cell_to_editor(self):
        if not self.selected_cell.is_solid:
            return

        self.texture_entry.delete(0, tk.END)
        self.texture_entry.insert(0, self.selected_cell.texture)
        self.color_hex.delete(0, tk.END)
        self.color_hex.insert(0, f"{self.selected_cell.color:08x}")

    def create_wall(self):
        if self.selected_x is None or self.selected_y is None:
            messagebox.showwarning("No cell selected", "Click on a cell first.")
            return
        texture = self.texture_entry.get()
        try:
            color = int(self.color_hex.get(), 16)
        except ValueError:
            messagebox.showerror("Invalid color", "Must be a valid hex RGBA value.")
            return
        self.selected_cell = MapCell(True, texture, color)
        self.update_cell_color(self.selected_x, self.selected_y)

    def destroy_wall(self):
        if self.selected_x is None or self.selected_y is None:
            messagebox.showwarning("No cell selected", "Click on a cell first.")
            return
        self.selected_cell = MapCell(False, "", int(DEFAULT_COLOR_HEX, 16))
        self.update_cell_color(self.selected_x, self.selected_y)

    def pick_color(self):
        color = colorchooser.askcolor()[1]
        if color is not None:
            self.color_hex.delete(0, tk.END)
            self.color_hex.insert(0, color.lstrip("#") + "ff")

    def export_map(self) -> None:
        if self.map is None:
            messagebox.showerror("Error", "No map to export.")
            return

        filename = filedialog.asksaveasfilename(defaultextension=".mdsc", filetypes=[("Map Files", "*.mdsc")])
        if not filename:
            return

        try:
            with open(filename, "wb") as file:
                file.write(self.map.to_bytes())
        except Exception as e:
            messagebox.showerror("Error", f"Failed to write map file:\n{e}")
        else:
            messagebox.showinfo("Export Complete", f"Map saved to {filename}")

    def load_map(self, path: str) -> None:
        if not os.path.exists(path):
            messagebox.showerror("Error", f"File not found: {path}")
            return
        try:
            with open(path, "rb") as file:
                self.map = Map.from_file(file)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to load map file:\n{e}")
            return

        self.grid_width = self.map.width
        self.grid_height = self.map.width
        self.width_entry.delete(0, tk.END)
        self.width_entry.insert(0, str(self.map.width))
        self.height_entry.delete(0, tk.END)
        self.height_entry.insert(0, str(self.map.height))

        self.canvas.delete("all")
        self.cell_ids = {}

        total_width = self.map.width * self.cell_size
        total_height = self.map.height * self.cell_size
        self.canvas.config(scrollregion=(0, 0, total_width, total_height))

        for y in range(self.map.height):
            for x in range(self.map.width):
                x1 = x * self.cell_size
                y1 = y * self.cell_size
                x2 = x1 + self.cell_size
                y2 = y1 + self.cell_size
                rect_id = self.canvas.create_rectangle(x1, y1, x2, y2, fill="white", outline="black")
                self.cell_ids[x, y] = rect_id

        for y in range(self.map.height):
            for x in range(self.map.width):
                cell = self.map[x, y]
                if cell.texture and cell.is_solid:
                    if cell.texture not in self.texture_display_color:
                        self.texture_display_color[cell.texture] = random.randint(0, 0xffffff)
                self.update_cell_color(x, y)


def parse_args():
    parser = argparse.ArgumentParser(description="Launch Wolf3D Map Editor")
    parser.add_argument("-t", "--texture", type=str, default=DEFAULT_TEXTURE, help="Sets the default texture ID")
    parser.add_argument("-c", "--color", type=str, default=DEFAULT_COLOR_HEX, help="Sets the default RGBA value")
    parser.add_argument("-l", "--load_file", type=str, help="Loads the map at the given path")
    return parser.parse_args()


def main():
    args = parse_args()
    try:
        color_int = int(args.color.lstrip("#"), 16)

    except ValueError:
        print("Invalid color RGBA provided. The given color has to be in hexadecimal.", file=sys.stderr)
        exit(2)

    app = MapEditor(default_texture=args.texture, default_color=color_int)

    # Load given map (if present):
    if args.load_file is not None:
        app.load_map(args.load_file)

    # Run the app:
    app.mainloop()


if __name__ == "__main__":
    main()
