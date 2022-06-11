import random

def swap(v, a, b):
	tmp = v[a]
	v[a] = v[b]
	v[b] = tmp

def partition(v, p, r):
	x = v[r-1]
	q = p-1
	for i in range(p, r):
		if v[i] <= x:
			q += 1
			swap(v, i ,q)
	return q

def partition_random(v, p, r):
	i = random.choice(range(p,r))
	swap(v, i, r-1)
	return partition(v, p, r)

def quick_sort_divide(v, p, r):
	if r - p > 1:
		q = partition(v, p, r)
		quick_sort_divide(v, p, q)
		quick_sort_divide(v, q+1, r)

def quick_sort_divide_random(v, p, r):
	if r - p > 1:
		q = partition_random(v, p, r)
		quick_sort_divide_random(v, p, q)
		quick_sort_divide_random(v, q+1, r)

def quick_sort(v):
	quick_sort_divide(v, 0, len(v))
	return v

def quick_sort_random(v):
	quick_sort_divide_random(v, 0, len(v))
	return v

def k_smaller_divide(v, k, p, r):
	if p == r:
		return v[p]
	q = partition_random(v, p, r)
	if q - p == k - 1:
		return v[q]
	elif q - p >= k:
		return k_smaller_divide(v, k, p, q-1)
	else:
		return k_smaller_divide(v, k - ((q-p)+1), q+1, r)

def k_smaller(v, k):
	return k_smaller_divide(v, k, 0, len(v))

def k_greater(v, k):
	return k_smaller_divide(v, len(v)+1 - k, 0, len(v))

a = [7,14,1220,547,1,28,22,13,31,19,16,25]
quick_sort(a)

b = [4, 432, 42, 6, 36]
quick_sort(b)

c = [540, 574, 737, 816, 429, 148]
quick_sort(c)

k_greater(a, 4)
