def insertion_sort(array):
    N = len(array)
    for i in range(N):
        for j in range(i, 0, -1):
            if array[j] < array[j-1]:
                exchange(j, j-1, array)
    return array

def exchange(i, j, array):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

print(insertion_sort([6,3,2,0,10,4,2]))
