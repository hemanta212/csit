def sel_sort(array):
    N = len(array)
    for i in range(N):
        a_min = i
        for j in range(i+1, N):
            if array[j] < array[a_min]:
                a_min = j
        exchange(a_min, i, array)
    return array

def exchange(i, j, array):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

print(sel_sort([5,4,3,4,0,5,2]))
