def binary_search(array, lo, hi, num):
    while True:
        if hi < lo:
            return
        mid = round( (hi+lo)/2 )
        elem = array[mid]
        if elem == num:
            return mid
        elif elem < num:
            lo = mid + 1
        elif elem > num:
            hi = mid - 1

def search(array, num):
    index = binary_search(array, 0, len(array)-1, num)
    return {'IN' : array, 'at' : index}

print(search([5,6,8,12,14,17,25,29,31,36,42,47,53,55,62], 42))
print(search([1,2,3,4,5,6,7,8,9,10], 7))
print(search([1], 1))
print(search([1,2], 1))
print(search([1,2], 2))
