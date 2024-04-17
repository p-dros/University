import tkinter as tk
from tkinter import Label, StringVar
from datetime import datetime
from tkcalendar import Calendar

okno = tk.Tk()
okno.title("Zegar i Kalendarz")
okno.geometry("400x400")
okno.configure(bg='pink')
okno.resizable(False, False)

date_time_var = StringVar()

def update_date_time():
    current_time = datetime.now()
    
    day = current_time.strftime('%d')
    month = current_time.strftime('%B')
    year = current_time.strftime('%Y')
    time_str = current_time.strftime('%H:%M:%S')
    day_of_week = current_time.strftime('%A')

    dt = f"{day_of_week}\n{day} {month} {year}\n{time_str}"
    date_time_var.set(dt)
    
    date_time.after(1000, update_date_time)
    
    return current_time

date_time = Label(okno, textvariable=date_time_var, font=('Arial', 18), bg='skyblue', width=20, height=4)
date_time.pack(anchor="center")

curr_time =  update_date_time()

cal_frame = tk.Frame(okno)
cal_frame.pack(pady=10)

cal = Calendar(cal_frame, selectmode="day", year=2024, month=1, day=1)
cal.pack()

okno.mainloop()
