#!/usr/bin/python3
"""
makeChange Method
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total.
    """
    if total <= 0:
        return 0
    value = 0
    while(len(coins) and total):
        mx = max(coins)
        result = total // mx
        rest = mx % total
        coins.remove(mx)
        if not result:
            continue
        total -= mx * result
        value += result
    if not total:
        return value
    return -1
