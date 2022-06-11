#!/bin/python
import math

def gdc(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    return gdc(b, a%b)

# get c such that b.c = 1 mod a
def modinv(a, b):
    d = gdc(a, b)
    if b > a:
        b = b % a
    x2, y2 = 1, 0
    x1, y1 = 0, 1
    r2, r1 = a, b
    while True:
        q = math.floor(r2 / r1)
        r = r2 % r1
        x = x2 - x1*q
        y = y2 - y1*q
        if r == d:
            return y % a
        x2, y2 = x1, y1
        x1, y1 = x, y
        r2 = r1
        r1 = r

def crt(p, r):
    M = 1
    n = len(p)
    for i in range(n):
        M = M * p[i]
    x = 0
    for i in range(n):
        m = M/p[i]
        m_inv = modinv(p[i], m)
        x = (x + m * m_inv * r[i]) % M
    return x
