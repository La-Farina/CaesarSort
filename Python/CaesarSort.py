def caesar_sort_sorting(arr):
    """Sort small arrays (<=5 items) using insertion-style micro-battles"""
    n = len(arr)
    if n <= 1:
        return
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def find_pivot_closest_to_average(arr):
    """Find pivot = element closest to average"""
    avg = sum(arr) / len(arr)
    closest = arr[0]
    min_diff = abs(arr[0] - avg)
    for val in arr[1:]:
        diff = abs(val - avg)
        if diff < min_diff:
            min_diff = diff
            closest = val
    return closest

def caesar_sort_dividing(arr):
    """Recursive divide-and-conquer CaesarSort"""
    n = len(arr)
    if n <= 5:
        caesar_sort_sorting(arr)
        return arr

    pivot = find_pivot_closest_to_average(arr)
    left, right = [], []
    pivot_placed = False

    for val in arr:
        if val < pivot:
            left.append(val)
        elif val > pivot:
            right.append(val)
        else:
            if not pivot_placed:
                pivot_placed = True
            else:
                left.append(val)  # duplicates go left

    caesar_sort_dividing(left)
    caesar_sort_dividing(right)

    arr[:] = left + [pivot] + right
    return arr

def caesar_sort(arr):
    caesar_sort_dividing(arr)
    return arr
