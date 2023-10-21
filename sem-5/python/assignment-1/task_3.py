import time
from datetime import datetime

rightarrow = chr(16)
leftarrow = chr(17)

last_second = None
while True:
    now = datetime.now()
    if now.second != last_second:
        last_second = now.second
        current_time = f"{now.hour}:{now.minute}:{now.second:02d}"
        print(f"{rightarrow}  {current_time}  {leftarrow}", end="\r")
    time.sleep(0.5)
