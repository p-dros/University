import sys
import math


def get_factor_list(num: int) -> list[int]:
    factors = []
    while num % 2 == 0:
        factors.append(2)
        num = int(num / 2)

    for i in range(3, int(math.sqrt(num) + 1), 2):
        while num % i == 0:
            factors.append(i)
            num = int(num / i)

    if num > 2:
        factors.append(num)

    return factors


def parse_factors(factors: list[int]) -> str:
    factor_counts = {}

    for factor in factors:
        if factor in factor_counts:
            factor_counts[factor] += 1
        else:
            factor_counts[factor] = 1
    factor_strs = []
    for factor, count in factor_counts.items():
        if count == 1:
            factor_strs.append(str(factor))
        else:
            factor_strs.append(f"{factor}^{count}")
    return "*".join(factor_strs)


if __name__ == "__main__":
    argv = sys.argv[1:]

    numbers = [int(arg) for arg in argv if arg.isdigit()]
    if len(numbers) == 0:
        print("Please enter at least one integer number")
        exit(1)

    for num in numbers:
        print(f"{num} = {parse_factors(get_factor_list(num))}")
