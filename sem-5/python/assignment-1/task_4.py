import time

LENGTH = 100
PERCENT_PER_SECOND = 20


def get_progress_bar(percent):
    filled_length = int(LENGTH * percent / 100)
    bar = "=" * filled_length + "-" * (LENGTH - filled_length)
    return f"|{bar}| {percent}%"


if __name__ == "__main__":
    for i in range(101):
        print(get_progress_bar(i), end="\r")
        time.sleep(1 / PERCENT_PER_SECOND)
    print()
    input("Press anything to exit...")
