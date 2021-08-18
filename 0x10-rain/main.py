#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [2, 1, 0, 3, 0, 2, 3, 0, 1, 0, 0, 5]
    print(rain(walls))
