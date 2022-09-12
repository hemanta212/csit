import random

def partition(array, lo, hi):
    par, i, j = array[lo], lo+1, hi
    while True:
        while array[i] <= par:
            if i == hi:
                break
            i += 1

        while array[j] > par:
            j -= 1
            if j == lo:
                break

        if j <= i:
            break
        array[j], array[i] = array[i], array[j]

    array[lo], array[j] = array[j], array[lo]
    return j

def quicksort(array, lo, hi):
    if hi <= lo:
        return
    j = partition(array, lo, hi)
    quicksort(array, lo, j-1)
    quicksort(array, j+1, hi)

def sort(array):
    random.shuffle(array)
    quicksort(array, 0, len(array)-1)
    return array

print(sort([5,4,3,0,2,7,9,1,5]))
print(sort([0,2,1]))
print(sort([3,1,2]))
print(sort([3,1]))
print(sort([1,3]))
