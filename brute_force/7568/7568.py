import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = []
for _ in range(n):
    arr.append(tuple(map(int, input().split())))

for me in arr:
    count = 1
    for other in arr:
        if other[0] > me[0] and other[1] > me[1]:
            count += 1
    print(count, end=' ')