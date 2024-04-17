START_NUM = 1
LENGTH = 100

max_num = START_NUM + LENGTH - 1
max_num_len = len(str(max_num))
DIGITS_COUNT = 2 + max_num_len

start_num_digit_count = len(str(START_NUM))
measure = ""

measure += f'{" " * (start_num_digit_count - 1)}|'
for num in range(LENGTH - 1):
    measure += f'{"." * DIGITS_COUNT}|'
measure += "\n"

space_count = 0
for num in range(START_NUM, LENGTH + START_NUM):
    measure += f"{' ' * space_count}{num}"

    digit_count = len(str(num + 1))
    space_count = DIGITS_COUNT + 1 - digit_count

print(measure)
