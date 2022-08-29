"""
Weighted quick-union implementation of Union-Find Algorithm
"""

array = [i for i in range(10)]
size = [1 for i in range(10)]


def main():
    nums = input(">> ")
    first, second = [int(i) for i in nums.split(" ")]

    union(first, second)
    found = find(first, second)

    print(f"{first}----{second}")
    print(array)
    print(found)


def find(first, second):
    root_f, root_s = root(first), root(second)
    return root_f == root_s


def root(index):
    if index == array[index]:
        return index
    return root(array[index])


def union(first, second):
    root_f, root_s = root(first), root(second)
    if root_f == root_s:
        return

    if size[root_f] > size[root_s]:
        array[root_s] = root_f
        size[root_f] += size[root_s]
    else:
        array[root_f] = root_s
        size[root_s] += size[root_f]


if __name__ == "__main__":
    main()
