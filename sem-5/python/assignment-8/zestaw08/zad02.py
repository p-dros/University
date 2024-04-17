import PyPDF2
import tkinter as tk
from tkinter import filedialog

okno = tk.Tk()
okno.title("PDF Reader")
okno.geometry("600x400")

text = tk.Text(okno, wrap="word", font=("Arial", 12))
text.pack(pady=20, padx=20, fill="both", expand=True)

def clear_text():
    text.delete(1.0, tk.END)

def open_pdf():
    file = filedialog.askopenfilename(title="Select a PDF", filetype=(("PDF Files", "*.pdf"), ("All Files", "*.*")))
    if file:
        pdf_file = PyPDF2.PdfReader(file)
        for i in range(len(pdf_file.pages)):
            page = pdf_file.pages[i]
            content = page.extract_text()
            text.insert(tk.END, content)

def quit_app():
    okno.destroy()

menu_bar = tk.Menu(okno)

file_menu = tk.Menu(menu_bar, tearoff=0)
file_menu.add_command(label="Open", command=open_pdf)
file_menu.add_command(label="Clear", command=clear_text)
file_menu.add_separator()
file_menu.add_command(label="Quit", command=quit_app)

menu_bar.add_cascade(label="File", menu=file_menu)
okno.config(menu=menu_bar)

okno.mainloop()
