"""
Percolation problem, N by N grid with all closed sites, then site opens one by one, connecting with all neighbouring cells.
The Program determines if a given system percolates i.e a path exists from the top to bottom.
uses union-find algorithm with path compression

TODO This program currently seems like a N^4 complexity, need to figure out. Desired complexity is N^2 logN
"""
import random
import time


class Percolation:
    def __init__(self, N=10):
        self.N = N
        self.grid = self.init_grid()
        self.record, self.size = self.init_record_and_size()

    def run(self, pause=False):
        start = time.time()
        self.set_virtual_node()
        self.cycle()
        while True:
            if pause and input("again? "):
                self.cycle()
            elif self.percolates():
                print("End ----------------")
                break
            else:
                self.cycle()
        end = time.time()
        print("Finished in ", end - start, " secs")

    def init_grid(self):
        row_gen = ["X" for i in range(self.N)]
        grid = [row_gen[:] for i in range(self.N)]
        return grid

    def init_record_and_size(self):
        record = [i for i in range(self.N * self.N + 2)]
        size = [1 for i in range(self.N * self.N + 2)]
        return record, size

    def log(self):
        for row in self.grid:
            for num in row:
                print(f"{str(num):4}", end="")
            print()

    def gen_random_pos(self):
        return (random.randint(1, self.N), random.randint(1, self.N))

    def open(self, i, j):
        self.grid[i - 1][j - 1] = "O"
        neighbours = self.get_neighbour(i, j)
        index_i = self.index(i, j)
        for (m, n) in neighbours:
            # print("checking neighbour ", m, n)
            if self.is_open(m, n):
                index_j = self.index(m, n)
                print(f"connecting ({i},{j})-->({m},{n}) | {index_i}-->{index_j}")
                self.union(index_i, index_j)

    def union(self, i, j):
        r_i, r_j = self.root(i), self.root(j)
        if r_i == r_j:
            return

        if self.size[r_i] <= self.size[r_j]:
            self.record[r_i] = r_j
            self.size[r_j] += self.size[r_i]
        else:
            self.record[r_j] = r_i
            self.size[r_i] += self.size[r_j]

    def root(self, i):
        while True:
            if i == self.record[i]:
                return i
            i = self.record[i]

    def index(self, i, j):
        return i * self.N - (self.N - j) - 1

    def is_open(self, i, j):
        return self.grid[i - 1][j - 1] == "O"

    def get_neighbour(self, i, j):
        top, bottom = (i + 1, j), (i - 1, j)
        left, right = (i, j - 1), (i, j + 1)
        valid_coords = [
            (i, j)
            for i, j in (top, bottom, left, right)
            if (i > 0 and i <= self.N) and (j > 0 and j <= self.N)
        ]
        return valid_coords

    def set_virtual_node(self):
        top_row = range(self.N)
        last_index = self.N * self.N - 1
        bottom_row = range(last_index, last_index - self.N, -1)
        for i in top_row:
            self.union(i, self.record[-2])
        for j in bottom_row:
            self.union(j, self.record[-1])

    def percolates(self):
        return self.root(self.record[-2]) == self.root(self.record[-1])

    def cycle(self):
        i, j = self.gen_random_pos()
        while self.is_open(i, j):
            print(".", end="")
            i, j = self.gen_random_pos()
        print("\nOpening ------------- ", i, j)
        self.open(i, j)
        self.log()
        print("------------------------")
