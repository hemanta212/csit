def shell_sort(array):
    N = len(array)
    # Compute the last increment
    h = 1
    while (h < N/3):
        h = 3*h + 1 # The 3x + 1 increment sequence

    while (h >= 1):
        for i in range(h, N):
            for j in range(i, 0, -h):
                if j >= h and array[j] < array[j-h]:
                    array[j], array[j-h] = array[j-h], array[j]
        h = int(h/3)
    return array

print(shell_sort([5,6,4,3,0,2,3]))
