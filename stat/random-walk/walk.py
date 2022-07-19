"""Simulation of Drunkard person walking 1000 steps."""
import math
import random


def walk_2d(nsteps):
    """Return destination coord after walk of n steps."""
    x, y = 0, 0
    pos_log = [(x, y)]
    for _ in range(nsteps):
        dx, dy = random.choice(
            [
                (0, 1),  # NORTH (UP)
                (0, -1),  # SOUTH (DOWN)
                (1, 0),  # EAST (RIGHT)
                (-1, 0),  # WEST (LEFT)
            ]
        )
        # Add pos with direction (x1, y1) with (x2, y2) -> x1+x2 , y1+y2
        x += dx
        y += dy
        # Log this step in log history
        pos_log.append((x, y))

    # distance_from_start = math.sqrt(pow(pos[x] - 0, 2) + pow(pos[y] - 0, 2))
    return pos_log


def walk_3d(nsteps):
    """Return destination coord after walk of n steps."""
    x, y, z = 0, 0, 0
    pos_log = [(x,y,z)]
    for _ in range(nsteps):
        dx, dy, dz = random.choice(
            [
                (1, 0, 0),  # EAST (RIGHT)
                (-1, 0, 0),  # WEST (LEFT)
                (0, 1, 0),  # NORTH (UP)
                (0, -1, 0),  # SOUTH (DOWN)
                (0, 1, 0),  # UP
                (0, -1, 0),  # DOWN
            ]
        )
        # Add pos with direction (x1, y1, z1) with (x2, y2, z2) -> x1+x2 , y1+y2, x3+y3+z3
        x += dx
        y += dy
        z += dz
        pos_log.append((x, y, z))

    # distance_from_start = math.sqrt(pow(pos[x] - 0, 2) + pow(pos[y] - 0, 2))
    return pos_log


def run(walk_func):
    max_dist, avg_dist = 0, 0
    for i in range(1, 1001):
        log = walk_func(1000)
        pos = log[-1]
        dist = sum([abs(i) for i in pos])
        avg_dist = (avg_dist + dist) / i
        max_dist = dist if dist > max_dist else max_dist
    print(
        f"**Simulation Result**\n\nAverage Distance: {avg_dist:.3f}\nMaximum Distance: {max_dist}\n\n"
    )


if __name__ == "__main__":
    run(walk_2d)
    run(walk_3d)
