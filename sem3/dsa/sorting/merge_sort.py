def merge(array, aux, mid, low, high):
    """Assumes array is sorted from 0 to mid and mid+1 to N"""
    for i in range(low, high+1): # Copy operation
        aux[i] = array[i]
    # i points to A's first, j to B's first and K to aux array's first
    i, j = low, mid+1
    A = array[low:mid]
    B = array[mid+1:high+1]
    for k in range(low, high+1):
        if i > mid:
            array[k] = aux[j]
            j += 1
            continue
        elif j > high:
            array[k] = aux[i]
            i+=1
            continue
        else:
            if aux[i] < aux[j]:
                array[k] = aux[i]
                i+=1
            else:
                array[k] = aux[j]
                j+=1
    return aux

def mergesort(array, aux, low, high):
    if low >= high:
        return
    mid = int(low + (high-low)/2)
    mergesort(array, aux, low, mid)
    mergesort(array,aux, mid+1, high)
    merge(array, aux, mid, low, high)

def sort(array):
    aux = array[:]
    mergesort(array, aux, 0, len(array)-1)
    return array

print(sort([4,2,0,5,2,9,1,0, 3]))
