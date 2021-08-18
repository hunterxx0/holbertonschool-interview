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
    lmt = len(spaces) - 1
    while (c < lmt):
        x0 = spaces[c]
        x1 = spaces[c + 1]
        if ((x0[0] + 1 == x1[0] and x0[1] == x1[1]) or
                (x0[0] == x1[0] and x0[1] + 1 == x1[1])):
            mx = max(x0[1], x1[1])
            mn = min(x1[0], x0[0])
            if x0[0] == mn and x0[1] == mx:
                spaces.remove(x1)
            else:
                spaces.remove(x0)
            c -= 1
            lmt -= 1
        else:
            c += 1
    wt = calct(walls, spaces)
    return wt
