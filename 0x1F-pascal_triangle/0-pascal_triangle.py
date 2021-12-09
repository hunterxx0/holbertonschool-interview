#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Pascal's Triangle
    """
    res = []
    if n <= 0:
        return res
    for i in range(1, n+1):
        tmp = []
        c = 1
        for j in range(1, i+1):
            tmp.append(c)
            c = c * (i - j) // j
        res.append(tmp)

    return res
