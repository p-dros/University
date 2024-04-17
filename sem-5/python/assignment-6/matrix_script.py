#!/bin/python3

import math
import os
import random
import re
import sys


first_multiple_input = input().rstrip().split()

n = int(first_multiple_input[0])

m = int(first_multiple_input[1])

matrix = []

for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

transposed_matrix = zip(*matrix)
decoded_text = "".join("".join(col) for col in transposed_matrix)

decoded_text = re.sub(
    r"(?<=[a-zA-Z0-9])[^a-zA-Z0-9]+(?=[a-zA-Z0-9])", " ", decoded_text
)

print(decoded_text)
