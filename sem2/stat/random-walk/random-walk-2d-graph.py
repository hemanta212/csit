#!/usr/bin/env python
# coding: utf-8

# In[21]:


import math
import random

import matplotlib.pyplot as plt
import numpy as np

try:# ENABLE IF YOU"VE WIDGET SUPPORT
    import ipywidgets as widgets
except Exception:
    pass


# In[2]:


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


# In[20]:


def plot_walker(steps):
    position_travelled = walk_2d(steps)
    l_arr_x = np.array([i[0] for i in position_travelled])
    l_arr_y = np.array([i[1] for i in position_travelled])
    plt.plot(l_arr_x,l_arr_y, color ="blue")
    plt.show()

plot_walker(1000)


# In[24]:


try:
    widgets.interact(plot_walker, steps=(0, 500))
except Exception:
    pass


# In[7]:


def get_stats():
    max_dist, avg_dist = 0, 0
    for i in range(1, 1001):
        log = walk_2d(1000)
        pos = log[-1]
        dist = sum([abs(i) for i in pos])
        avg_dist = (avg_dist + dist) / i
        max_dist = dist if dist > max_dist else max_dist
    print(
        f"**Simulation Result**\n\nAverage Distance: {avg_dist:.3f}\nMaximum Distance: {max_dist}\n\n"
    )


# In[8]:


get_stats()


# In[ ]:




