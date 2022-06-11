#!/bin/python
import sys

def mdc(a, b):
    if b > a:
        tmp = b
        b = a
        a = tmp
    if a % b == 0:
        return b
    return mdc(a%b, b)

def mmc(a,b):
    return int(a*b/mdc(a,b))

argv = sys.argv
a = int(argv[1])
b = int(argv[2])

print(mdc(a, b))
