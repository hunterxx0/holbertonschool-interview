#!/usr/bin/python3
"""A function that solves the N queens puzzle: nqueens N
./101-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]"""
import sys


def freepos(N, b, s, i):
    """
    checks if it's possible to put the queen
    """
    for y in range(s):
        if b[y][i] == 1:
            return False
    for x, y in zip(range(s, -1, -1), range(i, -1, -1)):
        if b[x][y] == 1:
            return False
    for x, y in zip(range(s, -1, -1), range(i, N)):
        if b[x][y] == 1:
            return False
    return True


def check(b, N, s=0):
    if s == N:
        printsol(b, N)
        return
    for i in range(N):
        if freepos(N, b, s, i):
            b[s][i] = 1
            check(b, N, s + 1)
            b[s][i] = 0


def printsol(b, N):
    """
    prints the coordinates of the right pos
    """
    print("[", end="")
    for i in range(N):
        for j in range(N):
            if b[i][j] == 1:
                print("[{}, {}]".format(i, j), end="")
                if i < N - 1:
                    print(", ", end="")
    print("]")


def main():
    """
    the main NQueens function
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isnumeric():
        N = int(sys.argv[1])
    else:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    b = [[0 for x in range(N)] for y in range(N)]
    check(b, N)


if __name__ == '__main__':
    main()
