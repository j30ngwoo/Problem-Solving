import sys
input = lambda: sys.stdin.readline().strip()

t = int(input())
for _ in range(t):
    n = int(input())
    h = list(map(int, input().split()))

    s = set(h[:n - 2])
    if h[-1] != 1 or len(s) < n - 2:
        print(-1)
        continue
    
    result = [0] * n
    result[0], result[-1] = sorted(list(set(range(1, n + 1)) - s))
    l = 0
    r = n - 1
    for x in h[:n - 2]:
        if result[l] < result[r]:
            result[r - 1] = x
            r -= 1
        else:
            result[l + 1] = x
            l += 1
    print(' '.join(map(str, result)))

