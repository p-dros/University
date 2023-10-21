import time
import os

text = " Hello World! "
height = os.get_terminal_size().lines
direction = 1
position = 0

while True:
    os.system("cls" if os.name == "nt" else "clear")

    print("\n" * position + text)
    position += direction

    if position == 0 or position == height:
        direction *= -1

    time.sleep(0.05)
