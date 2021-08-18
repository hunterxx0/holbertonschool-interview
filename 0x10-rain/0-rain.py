#!/usr/bin/python3
"""
Rain
"""
def calct(walls, sp):
    """
    calculate how many square units of water
    will be retained after it rains.
    """
    print(sp)
    wt = 0
    for x in sp:
        lf = x[0]
        rt = x[1]
        mn = min(walls[lf], walls[rt])
        sub = walls[lf+1:rt]
        for z in sub:
            wt += mn - z
    return wt

def rain(walls):
    """
    Given a list of non-negative integers
    representing the heights of walls with unit width 1,
    as if viewing the cross-section of a relief map,
    calculate how many square units of water
    will be retained after it rains.
    """
    if not walls:
        return 0
    print(walls)
    spaces = []
    for c in range(1, len(walls)-1):
        lf = c - 1
        rt = c + 1
        while (walls[c] >= walls[lf] and lf > 0):
            lf -= 1
        while (walls[c] >= walls[rt] and rt < len(walls)-1):
            rt += 1
        if (walls[c] < walls[lf] and walls[c] < walls[rt]
                and (lf, rt) not in spaces):
            spaces.append((lf, rt))
    c = 0
    lmt = len(spaces)
    while (c < lmt):
        c2 = 0
        while (c2 < lmt):
            if spaces[c] != spaces[c2]:
                x0 = spaces[c]
                x1 = spaces[c2]
                if (x1[0] >= x0[0] and x1[1] <= x0[1]):
                    spaces.remove(x1)
                    if c2 < c:
                        c = c2
                        c2 += 1
                    lmt -= 1
                else:
                    c2 += 1
            else:
                c2 += 1
        c += 1
    wt = calct(walls, spaces)
    return wt
