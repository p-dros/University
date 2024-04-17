import PyPDF2
import tkinter as tk
from tkinter import filedialog, Text, Menu

window = tk.Tk()
window.title("My PDF text extractor")
window.geometry("800x600")

text = Text(window, wrap="word", font=("Verdana", 20))
text.pack(pady=30, padx=60, fill="none", expand=True)


def clear_text():
    text.delete("1.0", tk.END)


def open_pdf():
    file = filedialog.askopenfilename(
        title="Select a PDF", filetypes=(("PDF Files", "*.pdf"), ("All Files", "*.*"))
    )
    if file:
        pdf_file = PyPDF2.PdfReader(file)
        for i in range(len(pdf_file.pages)):
            page = pdf_file.pages[i]
            content = page.extract_text()
            text.insert(tk.END, content)


def quit_app():
    window.destroy()


menu_bar = Menu(window, bg="white", relief="flat", bd=0)
menu_bar.config(
    font=("Verdana", 15), bg="white", fg="black", activebackground="#cfedf9"
)
window.config(menu=menu_bar)

file_menu = Menu(menu_bar, tearoff=0, font=("Verdana", 14))
menu_bar.add_cascade(label="File", menu=file_menu)

file_menu.add_command(label="       Open      ", command=open_pdf)
file_menu.add_command(label="       Clear      ", command=clear_text)
file_menu.add_command(label="       Quit      ", command=quit_app)

window.mainloop()
