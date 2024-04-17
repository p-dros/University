import tkinter as tk
from tkinter import StringVar, Button, Entry
import tkinter.font as font

window = tk.Tk()
window.title("Calculator")

program_font = font.Font(family="Arial", size=20, weight="bold")

ans_entry = Entry(window, bd=4, width=30, font=program_font, bg="gray", fg="white")
ans_entry.grid(row=0, column=0, columnspan=5)

equation = {"num_1": "", "num_2": "", "oper": ""}


def mouse_button_release(event):
    global equation
    widg = event.widget
    text = widg.cget("text")

    if text in "0123456789":
        ans_entry.insert(len(ans_entry.get()), text)

    if text in "+-*/":
        if equation["num_1"]:
            equation["oper"] = text
            equation["num_2"] = ans_entry.get()
            ans_entry.delete(0, tk.END)
        else:
            # Jeśli jeszcze nie ma zapisanej pierwszej liczby, zapisz ją
            equation["num_1"] = ans_entry.get()
            equation["oper"] = text
            ans_entry.delete(0, tk.END)

    if text == "C":
        ans_entry.delete(0, tk.END)
        equation = {"num_1": "", "num_2": "", "oper": ""}

    if text == "=":
        if equation["num_1"] and equation["oper"] and ans_entry.get():
            equation["num_2"] = ans_entry.get()
            result = eval(f"{equation['num_1']} {equation['oper']} {equation['num_2']}")
            ans_entry.delete(0, tk.END)
            ans_entry.insert(0, str(result))
            equation.clear()
            equation["num_1"] = str(result)


for i in range(1, 10):
    btn = Button(
        window,
        text=str(i),
        padx=20,
        pady=30,
    )
    btn["font"] = program_font
    btn.grid(row=(i - 1) // 3 + 1, column=(i - 1) % 3, sticky=tk.N + tk.S + tk.E + tk.W)

other_buttons = [
    {"value": "0", "row": 4, "column": 1},
    {"value": "C", "row": 4, "column": 0},
    {"value": "=", "row": 4, "column": 2},
    {"value": "+", "row": 4, "column": 3},
    {"value": "-", "row": 3, "column": 3},
    {"value": "*", "row": 2, "column": 3},
    {"value": "/", "row": 1, "column": 3},
]

for btn_config in other_buttons:
    btn = Button(window, text=btn_config["value"], padx=20, pady=30)
    btn["font"] = program_font
    btn.grid(
        row=btn_config["row"],
        column=btn_config["column"],
        sticky=tk.N + tk.S + tk.E + tk.W,
    )

# sposób na reakcję
window.bind("<ButtonRelease-1>", mouse_button_release)

window.mainloop()
