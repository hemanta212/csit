"""
Stack implementation
"""

def client():
    stack = Stack()
    while True:
        user_input = input("> ")
        if user_input == "-" and not stack.is_empty():
            print(stack.pop())
        elif user_input != "-":
            stack.push(user_input)
        else:
            print("Empty Stack")


class Stack:
    def __init__(self):
        self.store = []

    def is_empty(self):
        return len(self.store) == 0

    def pop(self):
        return self.store.pop()

    def push(self, value):
        self.store.append(value)


if __name__ == "__main__":
    client()
