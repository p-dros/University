from monitoredArray import MonitoredArray


def insertion_sort(array: MonitoredArray, left=0, right=None):
    """Performs the insertion sort on the given array within the specified range.

    Args:
    array (MonitoredArray): The array to be sorted.
    left (int): The left index of the range to be sorted. Default is 0.
    right (int): The right index of the range to be sorted. Default is None, which
                 means the right index is set to the length of the array - 1.
    """
    if right is None:
        right = len(array) - 1

    i = left + 1
    while i <= right:
        j = i
        while j > left and array[j - 1] > array[j]:
            array[j - 1], array[j] = array[j], array[j - 1]
            j -= 1
        i += 1


def bubble_sort(array: MonitoredArray):
    """Performs an enhanced bubble sort on the given array.

    Args:
    array (MonitoredArray): The array to be sorted.
    """
    n = len(array)

    for i in range(n):
        swapped = False

        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

                swapped = True

        if not swapped:
            break


def shell_sort(array: MonitoredArray):
    """Performs shell sort on the given array.

    Args:
    array (MonitoredArray): The array to be sorted.
    """
    left = 0
    right = len(array) - 1

    h = 1
    while h <= (right - left) // 9:
        h = 3 * h + 1

    while h > 0:
        for i in range(left + h, right + 1):
            j = i

            item = array[i]
            while j >= left + h and item < array[j - h]:
                array[j] = array[j - h]
                j = j - h
            array[j] = item

        h = h // 3


def merge_sort(array: MonitoredArray, left=None, right=None):
    """Performs merge sort on the given array.

    Args:
    array (MonitoredArray): The array to be sorted.
    """
    if left is None:
        left = 0
    if right is None:
        right = len(array) - 1

    if left < right:
        middle = (left + right) // 2  # wyznaczanie środka
        merge_sort(array, left, middle)
        merge_sort(array, middle + 1, right)
        merge(array, left, middle, right)  # scalanie


def merge(array: MonitoredArray, left, middle, right):
    """Merges two sorted subarrays."""
    temp_array = [None] * (right - left + 1)
    left1 = left
    right1 = middle
    left2 = middle + 1
    right2 = right
    i = 0

    while left1 <= right1 and left2 <= right2:
        if array[left1] <= array[left2]:
            temp_array[i] = array[left1]
            left1 += 1
        else:
            temp_array[i] = array[left2]
            left2 += 1
        i += 1

    while left1 <= right1:
        temp_array[i] = array[left1]
        left1 += 1
        i += 1

    while left2 <= right2:
        temp_array[i] = array[left2]
        left2 += 1
        i += 1

    for i in range(right - left + 1):
        array[left + i] = temp_array[i]


def quick_sort(array: MonitoredArray, left=None, right=None):
    """Performs quick sort on the given array."""
    if left is None:
        left = 0
    if right is None:
        right = len(array) - 1

    if left < right:
        pivot = partition(array, left, right)

        quick_sort(array, left, pivot - 1)
        quick_sort(array, pivot + 1, right)


def partition(array: MonitoredArray, left, right):
    """Partitions the array into two parts."""

    x = array[right]
    i = left
    for j in range(left, right):
        if array[j] <= x:
            array[i], array[j] = array[j], array[i]
            i += 1
    array[i], array[right] = array[right], array[i]
    return i


def tim_sort(array: MonitoredArray):
    min_run = 32
    n = len(array)

    for i in range(0, n, min_run):
        insertion_sort(array, i, min((i + min_run - 1), n - 1))

    size = min_run
    while size < n:
        for start in range(0, n, size * 2):
            midpoint = start + size - 1
            end = min((start + size * 2 - 1), (n - 1))
            merge(array, start, midpoint, end)

        size *= 2

    return array


algorithms = [
    (insertion_sort, "Insertion Sort"),
    (bubble_sort, "Bubble Sort"),
    (shell_sort, "Shell Sort"),
    (merge_sort, "Merge Sort"),
    (quick_sort, "Quick Sort"),
    (tim_sort, "Tim Sort"),
]
