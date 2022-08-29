"""
Quick Find Implementation of Union-Find Algorithm
"""

array = [i for i in range(10)]


def main():
    nums = input(">> ")
    first, second = [int(i) for i in nums.split(" ")]

    union(first, second)
    found = find(first, second)

    print(f"{first}----{second}")
    print(array)
    print(found)


def find(first, second):
    return array[first] == array[second]


def union(first, second):
    item_to_change = array[first]
    for index, item in enumerate(array[:]):
        # print(f"Comparing {item} and {first}-{array[first]}")
        if item == item_to_change:
            # print("matched")
            array[index] = array[second]


if __name__ == "__main__":
    main()
