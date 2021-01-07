#!/usr/bin/python3


def minOperations(n):
    op = 0
    for i in range(2, n):
        while(n % i == 0):
            op += i
            n /= i
    return(op)
