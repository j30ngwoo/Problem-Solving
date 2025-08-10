def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    
    counts = [0] * (n + 1)
    max_val = 0
    count_double = 0

    for e in arr:
        counts[e] += 1
        if counts[e] == 2:
            count_double += 1
            max_val = e

    if arr[-1] > max_val:
        print(count_double * 2 + 1)
    else:
        print(count_double * 2 - 1)

t = int(input())
for _ in range(t):
    solve()