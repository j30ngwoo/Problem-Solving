import sys
input = lambda: sys.stdin.readline().strip()

arr = []
for _ in range(5):
    arr.append(input())

for x in range(max(map(len, arr))):
    for y in range(5):
        if len(arr[y]) > x:
            print(arr[y][x], end='')