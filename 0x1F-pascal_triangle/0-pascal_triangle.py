#!/usr/bin/python3
"""
Pascal's Triangle
"""
from math import factorial


def pascal_triangle(n):
    """
    Pascal's Triangle
    """
    res = []
    if n <= 0:
        return res
    for i in range(n):
        tmp = []
        for j in range(i+1):
            tmp.append(factorial(i)//(factorial(j)*factorial(i-j)))
        res.append(tmp)

    return res
