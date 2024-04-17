#!/bin/python3

from itertools import product


def f(x):
    return x * x


def maximize_expression(K, M, lists):
    combinations = product(*lists)
    max_value = 0

    for comb in combinations:
        value = sum(f(x) for x in comb) % M
        max_value = max(max_value, value)

    return max_value


if __name__ == "__main__":
    K, M = map(int, input().rstrip().split())

    lists = [list(map(int, input().rstrip().split()[1:])) for _ in range(K)]

    result = maximize_expression(K, M, lists)
    print(result)
