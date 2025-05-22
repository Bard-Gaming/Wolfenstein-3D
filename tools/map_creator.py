#!/bin/env python3

import tkinter as tk
import random
from tkinter import messagebox, filedialog


class MapCell:
    def __init__(self, is_solid: bool, texture: str, color: int):
        self.is_solid = is_solid
        self.texture = texture
        self.color = color

    def to_bytes(self) -> bytes:
        data = bytearray()
        data.append(self.is_solid)
        data.extend(self.texture.encode("ascii"))
        data.append(0)
        data.extend(self.color.to_bytes(4))

        return bytes(data)

    def __repr__(self) -> str:
        return "MapCell()"



class MapFile:
    def __init__(self):
        self.bytes = bytearray()


    def add_dimensions(self, width: int, height: int) -> None:
        self.bytes.extend(width.to_bytes(4))
        self.bytes.extend(height.to_bytes(4))


    def add_cell(self, cell: MapCell) -> None:
        self.bytes.extend(cell.to_bytes())


    def write(self, filename: str = "map.mdsc") -> None:
        with open(filename, "wb") as file:
            file.write(self.bytes)


    def __repr__(self) -> str:
        return "MapFile()"



class Application(tk.Tk):
    def __init__(self) -> None:
        super().__init__()
        self.title("Wolf 3D Map Generator")
        self.geometry("900x700")

        self.width_entry = tk.Entry(self)
        self.height_entry = tk.Entry(self)
        self.generate_button = tk.Button(self, text="Generate Grid", command=self.generate_grid)
        self.export_button = tk.Button(self, text="Export Map", command=self.export_map)

        tk.Label(self, text="Width:").pack()
        self.width_entry.pack()
        tk.Label(self, text="Height:").pack()
        self.height_entry.pack()

        self.generate_button.pack(pady=10)

        # 1. Scrollable canvas
        self.canvas = tk.Canvas(self, width=800, height=500)
        self.scrollable_frame = tk.Frame(self.canvas)

        # 2. Scrollbars
        scrollbar_y = tk.Scrollbar(self, orient="vertical", command=self.canvas.yview)
        scrollbar_x = tk.Scrollbar(self, orient="horizontal", command=self.canvas.xview)
        self.canvas.configure(yscrollcommand=scrollbar_y.set, xscrollcommand=scrollbar_x.set)

        # 3. Create a window inside the canvas to hold the frame
        self.canvas.create_window((0, 0), window=self.scrollable_frame, anchor="nw")

        # 4. Scroll region updates when the frame resizes
        self.scrollable_frame.bind(
            "<Configure>",
            lambda e: self.canvas.configure(scrollregion=self.canvas.bbox("all"))
        )

        # 5. Pack everything
        self.canvas.pack(fill="both", expand=True)
        scrollbar_y.pack(side="right", fill="y")
        scrollbar_x.pack(side="bottom", fill="x")

        self.export_button.pack(pady=10)

        self.cell_widgets = []

    def generate_grid(self):
        # Clear existing widgets
        for widget in self.scrollable_frame.winfo_children():
            widget.destroy()

        try:
            width = int(self.width_entry.get())
            height = int(self.height_entry.get())
        except ValueError:
            messagebox.showerror("Error", "Width and Height must be integers.")
            return

        self.cell_widgets = []

        for y in range(height):
            row = []
            for x in range(width):
                cell_frame = tk.Frame(self.scrollable_frame, borderwidth=1, relief="solid")
                cell_frame.grid(row=y, column=x, padx=1, pady=1)

                solid_var = tk.BooleanVar()
                solid_checkbox = tk.Checkbutton(cell_frame, text="S", variable=solid_var)
                solid_checkbox.pack()

                texture_entry = tk.Entry(cell_frame, width=6)
                texture_entry.insert(0, "")
                texture_entry.pack()

                color_entry = tk.Entry(cell_frame, width=6)
                color_entry.insert(0, "FF0000")
                color_entry.pack()

                row.append({
                    "solid": solid_var,
                    "texture": texture_entry,
                    "color": color_entry
                })
            self.cell_widgets.append(row)

    def export_map(self):
        if not self.cell_widgets:
            messagebox.showerror("Error", "You must generate the grid first.")
            return

        try:
            width = int(self.width_entry.get())
            height = int(self.height_entry.get())
        except ValueError:
            messagebox.showerror("Error", "Invalid dimensions.")
            return

        map_file = MapFile()
        map_file.add_dimensions(width, height)

        for row in self.cell_widgets:
            for cell in row:
                is_solid = cell["solid"].get()
                texture = cell["texture"].get()
                color_str = cell["color"].get()

                try:
                    color = int(color_str.lstrip("#"), 16)
                except ValueError:
                    messagebox.showerror("Error", f"Invalid color: {color_str}")
                    return

                map_cell = MapCell(is_solid, texture, color)
                map_file.add_cell(map_cell)

        filename = filedialog.asksaveasfilename(defaultextension=".mdsc", filetypes=[("Map Files", "*.mdsc")])
        if filename:
            map_file.write(filename)
            messagebox.showinfo("Success", f"Map saved to {filename}")



app = Application()
app.mainloop()


