#!/usr/bin/python3
"""
makeChange Method
"""


def count(g, x, y):
    """
    returns the perimeter of each island
    """
    c = 0
    ll = [1, -2, 1]
    if y+1 != len(g[x]) and g[x][y+1] == 0:
        c += 1
    if y > 0 and g[x][y-1] == 0:
        c += 1
    if x+1 != len(g) and g[x+1][y] == 0:
        c += 1
    if x > 0 and g[x-1][y] == 0:
        c += 1
    return c


def island_perimeter(grid):
    """
    returns the perimeter of the island
    """
    c = 0
    for x in range(0, len(grid)):
        for y in range(0, len(grid[x])):
            if grid[x][y] == 1:
                c += count(grid, x, y)
    return c
