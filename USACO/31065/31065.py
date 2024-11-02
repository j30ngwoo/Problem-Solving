from math import ceil, floor
import sys
input = lambda: sys.stdin.readline().strip()

H = 0
A = 1
T = 2

def f():
    n = int(input())
    h = list(map(int, input().split()))
    a = list(map(int, input().split()))
    t = list(map(int, input().split()))
    arr = list(zip(h, a, t))
    arr.sort(key=lambda x: x[T])

    min_ = 0
    max_ = float('inf')
    for i in range(n - 1):
        h1, a1 = arr[i][H], arr[i][A]
        h2, a2 = arr[i + 1][H], arr[i + 1][A]

        # h1 + a1 * x > h2 + a2 * x
        # (a1 - a2)x > h2 - h1
        if a1 - a2 > 0:
            min_ = max(min_, floor((h2 - h1) / (a1 - a2)) + 1)
        elif a1 - a2 < 0:
            max_ = min(max_, ceil((h2 - h1) / (a1 - a2)) - 1)
        else: # a1 - a2 == 0
            if not (h1 > h2):
                print(-1)
                return

    if max_ >= min_:
        print(min_)
    else:
        print(-1)

tc = int(input())
for _ in range(tc):
    f()
