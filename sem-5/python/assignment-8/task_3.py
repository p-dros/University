import tkinter as tk
from tkinter import Label, StringVar
from datetime import datetime
from tkcalendar import Calendar

okno = tk.Tk()
okno.title("Zegar i Kalendarz")
okno.geometry("1000x800")
okno.resizable(False, False)

# Utwórz StringVar
current_datetime = StringVar()


def update_date_time():
    current_time = datetime.now()

    # Pobierz poszczególne elementy daty i czasu
    day = current_time.strftime("%d")
    month = current_time.strftime("%B")
    year = current_time.strftime("%Y")
    time = current_time.strftime("%H:%M:%S")
    day_of_week = current_time.strftime("%A")

    # Utwórz tekst z bieżącą datą i czasem
    dt = f"{day_of_week}, {day} {month} {year}\n{time}"

    # Ustaw tekst za pomocą .set dla StringVar
    current_datetime.set(dt)

    # Rekurencyjne odświeżanie etykiety
    date_time.after(1000, update_date_time)


# Utwórz widget Label ustawiony na StringVar
date_time = Label(
    okno,
    textvariable=current_datetime,
    font=("Helvetica", 32),
    bg="black",
    fg="white",
    width=40,
    pady=20,
)
date_time.pack(anchor="center", pady=30)

# Utwórz kalendarz i ustaw dzisiejszą datę
cal = Calendar(
    okno,
    selectmode="day",
    year=datetime.now().year,
    month=datetime.now().month,
    day=datetime.now().day,
    font=("Helvetica", 24),
)
cal.pack(anchor="center")

update_date_time()

okno.mainloop()
