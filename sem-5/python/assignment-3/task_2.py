def iterative_revert(L: list, left: int, right: int) -> None:
    if left < 0 or right < 0 or left > len(L) or right > len(L):
        raise ValueError("Invalid arguments")

    while left < right:
        L[left], L[right] = L[right], L[left]
        left += 1
        right -= 1


def recursive_revert(L: list, left: int, right: int) -> None:
    if left < 0 or right < 0 or left > len(L) or right > len(L):
        raise ValueError("Invalid arguments")

    if left < right:
        L[left], L[right] = L[right], L[left]
        recursive_revert(L, left + 1, right - 1)


revert = iterative_revert


def test_revert():
    L1 = [1, 2, 3, 4, 5]
    revert(L1, 1, 3)
    assert L1 == [1, 4, 3, 2, 5], f"Test case 1 failed: {L1}"

    L2 = [10, 20, 30, 40, 50]
    revert(L2, 1, 3)
    assert L2 == [10, 40, 30, 20, 50], f"Test case 2 failed: {L2}"

    # Test case 3: Edge case (empty list)
    L3 = []
    revert(L3, 0, 0)
    assert L3 == [], f"Test case 3 failed: {L3}"

    # Test case 4: Reverting the whole list
    L4 = [1, 2, 3, 4, 5]
    revert(L4, 0, 4)
    assert L4 == [5, 4, 3, 2, 1], f"Test case 4 failed: {L4}"

    # Test case 5: Reverting a single-element list
    L5 = [42]
    revert(L5, 0, 0)
    assert L5 == [42], f"Test case 5 failed: {L5}"

    # Test case 6: Reverting a sublist with one element
    L6 = [11, 22, 33, 44, 55]
    revert(L6, 2, 2)
    assert L6 == [11, 22, 33, 44, 55], f"Test case 6 failed: {L6}"

    # Test case 7: Reverting the last two elements
    L7 = [101, 102, 103, 104, 105]
    revert(L7, 3, 4)
    assert L7 == [101, 102, 103, 105, 104], f"Test case 7 failed: {L7}"

    print("All test cases passed!")


# Run the test
test_revert()
