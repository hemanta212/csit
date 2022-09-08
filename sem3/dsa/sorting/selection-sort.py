def exchange(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

def selection_sort(array):
    for i in range(len(array)):
        min_item = i
        for j in range(i+1, len(array)):
            if array[j] < array[min_item]:
                min_item = j
        exchange(array, i, min_item)
    return array

if __name__ == "__main__":
    a1, a2 = [4,2,2,4,0,1], [0, 0]
    selection_sort(a1), selection_sort(a2)
    assert a1 == [0,1,2,2,4,4]
    assert a2 == [0, 0]
