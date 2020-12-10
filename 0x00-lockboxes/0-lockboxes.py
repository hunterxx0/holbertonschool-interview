#!/usr/bin/python3


def join(T, R):
    res = []
    for e in R:
        res += T[e]
    return res


def canUnlockAll(boxes):
    ind = 0
    tmp = list(set(boxes[0]) | {0})
    add = True
    while add:
        add = False
        for j in join(boxes, tmp[ind:]):
            if j not in tmp:
                tmp.append(j)
                ind += 1
                add = True
    return (len(tmp) == len(boxes))
