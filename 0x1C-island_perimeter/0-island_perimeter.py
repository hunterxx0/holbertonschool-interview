#!/usr/bin/python3
"""
makeChange Method
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island
    """
    arr_arr_len = len(grid)
    arr_len = len(grid[0])
    isl = 0
    surr = 0
    for i in range(arr_arr_len):
        for j in range(arr_len):
            if grid[i][j] == 1:
                isl += 1
                if i < arr_arr_len - 1 and grid[i + 1][j] == 1:
                    surr += 1
                if j < arr_len - 1 and grid[i][j + 1] == 1:
                    surr += 1
    return isl * 4 - 2 * surr
