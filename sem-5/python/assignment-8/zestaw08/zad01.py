import tkinter as tk
from tkinter import StringVar, Button, Entry
import tkinter.font as font

okno = tk.Tk()
okno.title("Prosty Kalkulator")

myFont = font.Font(family='Arial', size=20, weight='bold')

ans_entry = Entry(okno, bd=5, width=20, font=myFont, bg="skyblue", fg="white")
ans_entry.grid(row=0, column=0, columnspan=4)

buttons = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', 'C', '=', '+'
]

row_val = 1
col_val = 0

equation = {'num_1': '', 'num_2': '', 'oper': ''}

def button_click(value):
    if value in "0123456789":
        ans_entry.insert(len(ans_entry.get()), value)

    elif value in "+-*/":
        handle_operator(value)

    elif value == "C":
        clear_entry()

    elif value == "=":
        perform_calculation()

def handle_operator(operator):
    equation['num_1'] = ans_entry.get()
    equation['oper'] = operator
    ans_entry.delete(0, tk.END)

def clear_entry():
    ans_entry.delete(0, tk.END)
    equation.clear()

def perform_calculation():
    if equation['num_1'] and equation['oper'] and ans_entry.get():
        equation['num_2'] = ans_entry.get()
        result = calculate()
        ans_entry.delete(0, tk.END)
        ans_entry.insert(tk.END, str(result))

def calculate():
    try:
        num_1 = float(equation['num_1'])
        num_2 = float(equation['num_2'])
        oper = equation['oper']

        if oper == '+':
            return num_1 + num_2
        elif oper == '-':
            return num_1 - num_2
        elif oper == '*':
            return num_1 * num_2
        elif oper == '/':
            if num_2 != 0:
                return num_1 / num_2
            else:
                return "Error: Division by zero"
    except Exception as e:
        return "Error"

for button in buttons:
    tk.Button(okno, text=button, width=5, height=2, command=lambda b=button: button_click(b)).grid(row=row_val, column=col_val)
    col_val += 1
    if col_val > 3:
        col_val = 0
        row_val += 1

okno.mainloop()
