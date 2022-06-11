#!/bin/python
from random import random
from sys import argv

def word_add(D, word_sequence):
    d = D
    l = len(word_sequence)
    for i in range(l-1):
        w = word_sequence[i]
        if d.get(w) == None:
            d[w] = {}
        d = d[w]
    w = word_sequence[l-1]
    if d.get(w) == None:
        d[w] = 1
    else:
        d[w] += 1

def mk_word_frequency_fn(d):
    v = list(d.values())
    k = list(d.keys())
    s = sum(v)
    l = len(v)
    vr = [val/s for val in v]
    def myf(x):
        low = 0
        i = 0
        while i < l:
            up = low + vr[i]
            if low <= x <= up:
                return k[i]
            low = up
            i += 1
        return None
    return myf

def mk_dict_fn(d, depth):
    if depth == 1:
        return mk_word_frequency_fn(d)
    nd = {}
    for k in d.keys():
        nd[k] = mk_dict_fn(d[k], depth-1)
    return nd

def get_word(dict_fn, word_sequence, x):
    f = dict_fn
    l = len(word_sequence)
    for i in range(l):
        w = word_sequence[i]
        f = f[w]
    return f(x)

def predict(N,W,m):
    dicts = []
    for i in range(m):
        dicts.append({})
    l = len(W)
    for i in range(l):
        for j in range(m):
            if j > i or j >= l-i:
                break
            word_add(dicts[j], W[i:i+j+1])
    dict_fns = []
    for i in range(m):
        dict_fns.append(mk_dict_fn(dicts[i],i+1))
    NW = []
    j = 0
    for i in range(N):
        k = 0
        nw = ''
        while True:
            try:
                nw = get_word(dict_fns[j-k], NW[i-j+k:i+1], random())
                break
            except:
                k += 1
        NW.append(nw)
        j = j + 1
        if j > m-1:
            j = m-1
    return NW

words = list(input())
m = int(argv[1])
N = int(argv[2])
NW = predict(N,words,m)
print("".join(NW))
