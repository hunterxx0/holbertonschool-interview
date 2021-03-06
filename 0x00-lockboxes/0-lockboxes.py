#!/usr/bin/python3


def join(T, R):
    res = []
    for e in R:
        if e < len(T):
            res += T[e]
    return res


def canUnlockAll(boxes):
    if not boxes[0] or not len(boxes[0]):
        return(False)
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
