from tkinter import Label, StringVar, Button, PhotoImage, Entry, filedialog
import tkinter as tk
from PIL import Image, ImageTk

okno = tk.Tk()
okno.title("Skalowanie Zdjęć")
okno.geometry("500x400")
okno.resizable(False, False)

image_fp = None
data_image = None
photo_image = None

def open_handler():
    global image_fp, data_image
    image_fp = filedialog.askopenfilename(initialdir=".", filetypes=(("PNG Files", "*.png"),))
    if image_fp:
        image = Image.open(image_fp)
        data_image = ImageTk.PhotoImage(image)
        image_label.config(image=data_image)

def width_modified(event):
    global image_fp
    if image_fp:
        w = width_entry.get()
        if w != "" and w.isdigit():
            w = int(w)
            image = Image.open(image_fp)
            image_width = image.width
            image_height = image.height
            width_percentage = int((w*100)/image_width)
            height_set_to = int(image_height * (width_percentage/100))
            height_entry_str.set(str(height_set_to))

def height_modified(event):
    global image_fp
    if image_fp:
        h = height_entry.get()
        if h != "" and h.isdigit():
            h = int(h)
            image = Image.open(image_fp)
            image_width = image.width
            image_height = image.height
            height_percentage = int((h*100)/image_height)
            width_set_to = int(image_width * (height_percentage/100))
            width_entry_str.set(str(width_set_to))

def resize_handler():
    global image_fp, photo_image
    if image_fp:
        w = width_entry_str.get()
        h = height_entry_str.get()

        if w != "" and w.isdigit() and h != "" and h.isdigit():
            w = int(w)
            h = int(h)
            image = Image.open(image_fp)
            image.thumbnail((w, h), Image.LANCZOS)
            image.save('temp.png')
            photo_image = ImageTk.PhotoImage(file='temp.png')
            image_label.config(image=photo_image)

def save_handler():
    global image_fp, photo_image
    if image_fp:
        image_save_fp = filedialog.asksaveasfilename(initialdir=".", filetypes=(("PNG files", "*.png"),), defaultextension=".png")
        if image_save_fp:
            w = width_entry_str.get()
            h = height_entry_str.get()
            if w != "" and w.isdigit() and h != "" and h.isdigit():
                w = int(w)
                h = int(h)
                image = Image.open(image_fp)
                image.thumbnail((w, h), Image.LANCZOS)
                image.save(image_save_fp)

open_btn = Button(okno, text="Open", command=open_handler)
open_btn.grid(row=0, column=0, pady=10)

width_label = Label(okno, text="Width:")
width_label.grid(row=0, column=1)

width_entry_str = StringVar()
width_entry = Entry(okno, textvariable=width_entry_str)
width_entry.bind("<KeyRelease>", width_modified)
width_entry.grid(row=0, column=2)

height_label = Label(okno, text="Height:")
height_label.grid(row=0, column=3)

height_entry_str = StringVar()
height_entry = Entry(okno, textvariable=height_entry_str)
height_entry.bind("<KeyRelease>", height_modified)
height_entry.grid(row=0, column=4)

resize_btn = Button(okno, text="Resize", command=resize_handler)
resize_btn.grid(row=0, column=5, pady=10)

save_btn = Button(okno, text="Save", command=save_handler)
save_btn.grid(row=0, column=6, pady=10)

image_label = Label(okno)
image_label.config(image="")
image_label.grid(row=1, column=0, columnspan=7, padx=10, pady=50)

okno.mainloop()
