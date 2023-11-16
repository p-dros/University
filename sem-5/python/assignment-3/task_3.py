import matplotlib.pyplot as plt
import numpy as np
import re


def is_valid_expression(string: str):
    allowed_characters = re.compile(r"^[0-9\.\+\-\*\/\(\)xX\^ ]+$")
    return bool(allowed_characters.match(string))


def plot_polynomial(
    expression: str, x_min: float, x_max: float, file_name: str = "plot.png"
):
    if not is_valid_expression(expression):
        print("Invalid expression")
        exit()

    x_val = np.linspace(x_min, x_max, 1000)
    y_val = [eval(expression) for x in x_val]

    plt.figure(figsize=[9, 5])
    plt.plot(x_val, y_val, color="blue", linewidth=2.0, linestyle="-")
    plt.title(f"Plot of {expression}")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.grid(True)
    plt.savefig(file_name)


if __name__ == "__main__":
    expression = input("Enter the function: ")

    try:
        x_min = float(input("Enter the minimum x value: "))
        x_max = float(input("Enter the maximum x value: "))
    except ValueError:
        print("Invalid input for x_min or x_max. Please enter valid numerical values.")
        exit()

    plot_polynomial(expression, x_min, x_max)
