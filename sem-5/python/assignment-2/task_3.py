import argparse
import re

parser = argparse.ArgumentParser(
    description="Convert between Roman and Arabic numerals."
)
parser.add_argument("number", help="Number to convert (either Roman or Arabic)")

ROMAN_TO_ARABIC = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}

ARABIC_TO_ROMAN = {
    1: "I",
    4: "IV",
    5: "V",
    9: "IX",
    10: "X",
    40: "XL",
    50: "L",
    90: "XC",
    100: "C",
    400: "CD",
    500: "D",
    900: "CM",
    1000: "M",
}


def is_arabic(num_str):
    try:
        int(num_str)
        return True
    except ValueError:
        return False


def is_roman(roman_str):
    pattern = re.compile(r"^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$")
    return bool(pattern.match(roman_str))


def convert_to_arab(roman: str) -> int:
    print("Roman to Arabic conversion")
    result = 0
    prev_value = 0

    for numeral in reversed(roman):
        current_value = ROMAN_TO_ARABIC[numeral]

        if current_value < prev_value:
            result -= current_value
        else:
            result += current_value

        prev_value = current_value

    return result


def convert_to_roman(arabic: int) -> str:
    print("Arabic to Roman conversion")
    result = ""
    for value, numeral in sorted(
        ARABIC_TO_ROMAN.items(), key=lambda x: x[0], reverse=True
    ):
        while arabic >= value:
            result += numeral
            arabic -= value
    return result


def main():
    args = parser.parse_args()
    input_number = args.number

    if is_arabic(input_number):
        print(convert_to_roman(int(input_number)))
    elif is_roman(input_number):
        print(convert_to_arab(input_number))
    else:
        print("Invalid input. Please enter a valid Roman or Arabic numeral.")


if __name__ == "__main__":
    main()
