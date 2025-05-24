#!/bin/env python3

import tkinter as tk
from tkinter import colorchooser, messagebox, filedialog
from dataclasses import dataclass
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

    def to_bytes(self) -> bytes:
        if not self.is_solid:
            return b'\x00'
        array = bytearray()
        array.extend(b'\x01')
        array.extend(self.texture.encode("ascii") + b"\x00")
        array.extend(self.color.to_bytes(4))
        return bytes(array)

    @staticmethod
    def from_bytes(buffer: bytes, offset: int):
        if buffer[offset] == 0:
            return MapCell(False, "", int(DEFAULT_COLOR_HEX, 16)), offset + 1
        offset += 1
        end = buffer.index(0x00, offset)
        texture = buffer[offset:end].decode("ascii")
        offset = end + 1
        color = int.from_bytes(buffer[offset:offset + 4])
        offset += 4
        return MapCell(True, texture, color), offset


class MapEditor(tk.Tk):
    def __init__(self, default_texture=DEFAULT_TEXTURE, default_color=int(DEFAULT_COLOR_HEX, 16), load_file=None):
        super().__init__()
        self.title("Wolf3D Map Editor")
        self.geometry("1200x800")

        self.default_texture = default_texture
        self.default_color = default_color
        self.cell_size = 20
        self.map_data = []
        self.cell_ids = {}
        self.selected_x = None
        self.selected_y = None
        self.selection_overlay_id = None
        self.texture_display_color = {}

        self.setup_ui()

        if load_file:
            self.load_map(load_file)

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

        self.grid_width = width
        self.grid_height = height

        self.canvas.delete("all")
        self.map_data = [
            [MapCell(False, self.default_texture, self.default_color) for _ in range(width)]
            for _ in range(height)
        ]
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
        cell = self.map_data[y][x]
        if cell.is_solid:
            if cell.texture not in self.texture_display_color:
                self.texture_display_color[cell.texture] = random.randint(0, 0xFFFFFF)
            color = self.texture_display_color[cell.texture]
        else:
            color = int(DEFAULT_COLOR_HEX, 16)
        self.canvas.itemconfig(self.cell_ids[x, y], fill=f"#{(color >> 8) & 0xFFFFFF:06x}")


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
        cell = self.map_data[self.selected_y][self.selected_x]
        if not cell.is_solid:
            return
        self.texture_entry.delete(0, tk.END)
        self.texture_entry.insert(0, cell.texture)
        self.color_hex.delete(0, tk.END)
        self.color_hex.insert(0, f"{cell.color:08x}")

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
        self.map_data[self.selected_y][self.selected_x] = MapCell(True, texture, color)
        self.update_cell_color(self.selected_x, self.selected_y)

    def destroy_wall(self):
        if self.selected_x is None or self.selected_y is None:
            messagebox.showwarning("No cell selected", "Click on a cell first.")
            return
        self.map_data[self.selected_y][self.selected_x] = MapCell(False, "", int(DEFAULT_COLOR_HEX, 16))
        self.update_cell_color(self.selected_x, self.selected_y)

    def pick_color(self):
        color = colorchooser.askcolor()[1]
        if color:
            self.color_hex.delete(0, tk.END)
            self.color_hex.insert(0, color.lstrip("#") + "ff")

    def export_map(self):
        if not self.map_data:
            messagebox.showerror("Error", "No map to export.")
            return

        filename = filedialog.asksaveasfilename(defaultextension=".mdsc", filetypes=[("Map Files", "*.mdsc")])
        if not filename:
            return

        try:
            with open(filename, "wb") as f:
                f.write(self.grid_width.to_bytes(4))
                f.write(self.grid_height.to_bytes(4))
                for row in self.map_data:
                    for cell in row:
                        f.write(cell.to_bytes())
            messagebox.showinfo("Export Complete", f"Map saved to {filename}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to write map file:\n{e}")

    def load_map(self, path):
        if not os.path.exists(path):
            messagebox.showerror("Error", f"File not found: {path}")
            return
        try:
            with open(path, "rb") as f:
                buffer = f.read()
            width = int.from_bytes(buffer[0:4])
            height = int.from_bytes(buffer[4:8])

            self.grid_width = width
            self.grid_height = height
            self.width_entry.delete(0, tk.END)
            self.width_entry.insert(0, str(width))
            self.height_entry.delete(0, tk.END)
            self.height_entry.insert(0, str(height))

            self.canvas.delete("all")
            self.map_data = []
            self.cell_ids = {}

            total_width = width * self.cell_size
            total_height = height * self.cell_size
            self.canvas.config(scrollregion=(0, 0, total_width, total_height))

            offset = 8
            for y in range(height):
                row = []
                for x in range(width):
                    cell, offset = MapCell.from_bytes(buffer, offset)
                    row.append(cell)
                    x1 = x * self.cell_size
                    y1 = y * self.cell_size
                    x2 = x1 + self.cell_size
                    y2 = y1 + self.cell_size
                    rect_id = self.canvas.create_rectangle(x1, y1, x2, y2, fill="white", outline="black")
                    self.cell_ids[x, y] = rect_id
                self.map_data.append(row)

            for y in range(height):
                for x in range(width):
                    cell = self.map_data[y][x]
                    if cell.texture and cell.is_solid:
                        if cell.texture not in self.texture_display_color:
                            self.texture_display_color[cell.texture] = random.randint(0, 0xFFFFFF)
                    self.update_cell_color(x, y)
        except Exception as e:
            messagebox.showerror("Error", f"Failed to load map file:\n{e}")


def parse_args():
    parser = argparse.ArgumentParser(description="Launch Wolf3D Map Editor")
    parser.add_argument("-t", "--texture", type=str, default=DEFAULT_TEXTURE, help="Default texture ID")
    parser.add_argument("-c", "--color", type=str, default=DEFAULT_COLOR_HEX, help="Default hex color (e.g. FF0000)")
    parser.add_argument("-load", "--load_file", type=str, help="Path to .mdsc file to load and edit")
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    try:
        color_int = int(args.color.lstrip("#"), 16)
    except ValueError:
        print("Invalid color hex provided. Use format like FF0000.")
        sys.exit(1)

    app = MapEditor(default_texture=args.texture, default_color=color_int, load_file=args.load_file)
    app.mainloop()
