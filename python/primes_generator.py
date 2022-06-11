#!/bin/python
import sys

primes = [2]

def is_prime(n):
  if n < 2:
    return False

  for p in primes:
    if n % p == 0:
      return False
    if p*p > n:
      return True

  primes.append(n)
  return True

def gen_primes(n):
  i = primes[-1] + 1
  while i <= n:
    if is_prime(i):
      primes.append(i)
    i += 1

n = int(sys.argv[1])
gen_primes(n)
print(primes, sep=" ")
