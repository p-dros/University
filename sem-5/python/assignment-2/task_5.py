def fun(N: float):
    current_gap = 0
    max_gap = 0

    encountered_one = False

    while N > 0:
        last_bit = N & 1

        if last_bit == 1:
            max_gap = max(max_gap, current_gap)

            current_gap = 0
            encountered_one = True
        elif encountered_one:
            current_gap += 1

        N >>= 1

    return max_gap


if __name__ == "__main__":

    def test(N: float, expected: float):
        result = fun(N)
        print(f"Binary representation of {N}: {bin(N)[2:]}")
        print(f"fun({N}): {result}, expected: {expected}")
        assert result == expected

    test(9, 2)
    test(529, 4)
    test(20, 1)
    test(15, 0)
    test(1041, 5)
