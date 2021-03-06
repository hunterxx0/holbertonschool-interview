#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """ Minimum Operations """
    op = 0
    if n and isinstance(n, int) and n >= 2:
        for i in range(2, n):
            while(n % i == 0):
                op += i
                n /= i
    if n == 2:
        op = 2
    return(op)
