import sys
input = lambda: sys.stdin.readline().strip()

n, m = list(map(int, input().split()))
cows = list(map(int, input().split()))
canes = list(map(int, input().split()))

for cane_top in canes:
    cane_bottom = 0
    for i in range(len(cows)):
        if cows[i] > cane_bottom:
            eat = min(cows[i] - cane_bottom, cane_top - cane_bottom)
            cows[i] += eat
            cane_bottom += eat
            if cane_top == cane_bottom:
                break 

print('\n'.join(map(str, cows)))