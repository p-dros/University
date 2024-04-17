#!/bin/python3

string = input()


def custom_sort(s):
    lower_case = sorted([char for char in s if char.islower()])
    upper_case = sorted([char for char in s if char.isupper()])
    odd_digits = sorted([char for char in s if char.isdigit() and int(char) % 2 != 0])
    even_digits = sorted([char for char in s if char.isdigit() and int(char) % 2 == 0])

    return "".join(lower_case + upper_case + odd_digits + even_digits)


result = custom_sort(string)

print(result)
