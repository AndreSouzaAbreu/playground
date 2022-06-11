#  ╭────────────────────────╮
#  │ LINEAR EQUATION SOLVER │
#  ╰────────────────────────╯

def solve(M):
    m = len(M)
    n = m
    vi = []

    for i in range(0, m):
        vil = []
        for i in range(0, n+1):
            vil.append(0)
        vi.append(vil)

    for i in range(0, m):
        l = []
        for j in range(0, n+1):
            l.append(M[i][j])
        for k in range(0, i):
            for j in range(k+1, n):
                l[j] += l[k] * vi[k][j]
            l[n] -= l[k] * vi[k][n]
        vi[i][-1] = l[-1]/l[i]
        for j in range(i+1, n):
            vi[i][j] = -l[j]/l[i]

    x = [0] * n
    x[-1] = vi[-1][-1]
    for i in range(n-2, -1, -1):
        for j in range(i+1, n):
            x[i] += vi[i][j] * x[j]
        x[i] += vi[i][n]

    return x


solve([ [2, 5, 1, 33], [3, -2 , 4, 29] , [-3, 0, 2, 5] ])
solve([ [2, 5, 1, -1, 31], [3, -2 , 4, -1, 27] , [-3, 0, 2, -1, 3], [4, 2, 0, 3, 26]])
solve([ [2, 1, -2, 10], [3, 2, 2, 1], [5, 4, 3, 4]])
solve([ [1, 1, 1, 4], [2, 3, -2, 3], [1, 7, -7, 5]])
