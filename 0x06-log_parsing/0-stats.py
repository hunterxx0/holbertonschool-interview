#!/usr/bin/python3
""" Log parsing """
import signal
import sys

c = 0
size = 0
codes = {'200': 0,
         '301': 0,
         '400': 0,
         '401': 0,
         '403': 0,
         '404': 0,
         '405': 0,
         '500': 0
         }


try:
    for line in sys.stdin:
        num = line.split('"')[-1].split(" ")[1:]
        if !num or len(num) != 2:
            continue
            c += 1
        if num[0] in codes.keys():
            codes[num[0]] += 1
        size += int(num[1])
        if c % 10 == 0:
            print("File size: {}".format(size))
            for x, y in codes.items():
                if y:
                    print('{}: {}'.format(x, y))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(size))
    for x, y in codes.items():
        if y:
            print('{}: {}'.format(x, y))
