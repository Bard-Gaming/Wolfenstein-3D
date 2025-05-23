#!/bin/env python3

import tkinter as tk
from tkinter import colorchooser, messagebox, filedialog
from dataclasses import dataclass
import argparse
import sys

# === Default Parameters ===
DEFAULT_TEXTURE = "WALL"
DEFAULT_COLOR_HEX = "CCCCCC" #light gray
DEFAULT_SOLID = False


@dataclass
class MapCell:
    is_solid: bool
    texture: str
    color: int


class MapEditor(tk.Tk):
    def __init__(self, default_texture=DEFAULT_TEXTURE, default_color=int(DEFAULT_COLOR_HEX, 16), default_solid=DEFAULT_SOLID):
        super().__init__()
        self.title("Wolf3D Map Editor")
        self.geometry("1200x800")

        self.default_texture = default_texture
        self.default_color = default_color
        self.default_solid = default_solid

        self.cell_size = 20
        self.map_data = []
        self.cell_ids = {}
        self.selected_x = None
        self.selected_y = None

        self.setup_ui()

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

        self.solid_var = tk.BooleanVar()
        self.solid_var.set(self.default_solid)
        self.solid_checkbox = tk.Checkbutton(self.panel, text="Solid", variable=self.solid_var)
        self.solid_checkbox.pack()

        self.apply_button = tk.Button(self.panel, text="Apply to Cell", command=self.apply_changes)
        self.apply_button.pack(pady=10)

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
            [MapCell(self.default_solid, self.default_texture, self.default_color) for _ in range(width)]
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
                cell = self.map_data[y][x]
                x1 = x * self.cell_size
                y1 = y * self.cell_size
                x2 = x1 + self.cell_size
                y2 = y1 + self.cell_size
                color = f"#{cell.color:06x}"
                rect_id = self.canvas.create_rectangle(x1, y1, x2, y2, fill=color, outline="black")
                self.cell_ids[(x, y)] = rect_id

    def on_canvas_click(self, event):
        if not hasattr(self, "grid_width") or not hasattr(self, "grid_height"):
            return

        canvas_x = self.canvas.canvasx(event.x)
        canvas_y = self.canvas.canvasy(event.y)
        x = int(canvas_x // self.cell_size)
        y = int(canvas_y // self.cell_size)
        if 0 <= x < self.grid_width and 0 <= y < self.grid_height:
            self.selected_x = x
            self.selected_y = y
            self.load_cell_to_editor()

    def update_cell_color(self, x, y, color=None):
        if color is None:
            cell = self.map_data[y][x]
            color = f"#{cell.color:06x}"
        else:
            color = f"#{color:06x}"
        self.canvas.itemconfig(self.cell_ids[(x, y)], fill=color)

    def load_cell_to_editor(self):
        cell = self.map_data[self.selected_y][self.selected_x]
        self.texture_entry.delete(0, tk.END)
        self.texture_entry.insert(0, cell.texture)
        self.color_hex.delete(0, tk.END)
        self.color_hex.insert(0, f"{cell.color:06x}")
        self.solid_var.set(cell.is_solid)

    def apply_changes(self):
        if self.selected_x is None or self.selected_y is None:
            messagebox.showwarning("No cell selected", "Click on a cell in the grid first.")
            return

        texture = self.texture_entry.get()
        try:
            color = int(self.color_hex.get(), 16)
        except ValueError:
            messagebox.showerror("Invalid color", "Color must be a valid hex value like FF0000.")
            return

        is_solid = self.solid_var.get()
        cell = MapCell(is_solid, texture, color)
        self.map_data[self.selected_y][self.selected_x] = cell

        self.update_cell_color(self.selected_x, self.selected_y, 0x000000)

    def pick_color(self):
        color = colorchooser.askcolor()[1]
        if color:
            self.color_hex.delete(0, tk.END)
            self.color_hex.insert(0, color.lstrip("#"))

    def export_map(self):
        if not self.map_data:
            messagebox.showerror("Error", "No map to export.")
            return

        filename = filedialog.asksaveasfilename(defaultextension=".mdsc", filetypes=[("Map Files", "*.mdsc")])
        if not filename:
            return

        try:
            with open(filename, "wb") as f:
                f.write(self.grid_width.to_bytes(4, "big"))
                f.write(self.grid_height.to_bytes(4, "big"))
                for row in self.map_data:
                    for cell in row:
                        f.write(bytes([1 if cell.is_solid else 0]))
                        f.write(cell.texture.encode("ascii") + b"\x00")
                        f.write(cell.color.to_bytes(4, "big"))
            messagebox.showinfo("Export Complete", f"Map saved to {filename}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to write map file:\n{e}")


def parse_args():
    parser = argparse.ArgumentParser(description="Launch Wolf3D Map Editor")
    parser.add_argument("-t", "--texture", type=str, default=DEFAULT_TEXTURE, help="Default texture ID")
    parser.add_argument("-c", "--color", type=str, default=DEFAULT_COLOR_HEX, help="Default hex color (e.g. FF0000)")
    parser.add_argument("-s", "--solid", action="store_true", default=DEFAULT_SOLID, help="Default solid status")
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    try:
        color_int = int(args.color.lstrip("#"), 16)
    except ValueError:
        print("Invalid color hex provided. Use format like FF0000.")
        sys.exit(1)

    app = MapEditor(default_texture=args.texture, default_color=color_int, default_solid=args.solid)
    app.mainloop()
