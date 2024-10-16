import sys
input = lambda: sys.stdin.readline().strip()

grid_max = [0, 0, 0]
grid_min = [0, 0, 0]

n = int(input())
for i in range(n):
    newline_max = list(map(int, input().split()))
    newline_min = newline_max[:]
    newline_max[0] += max(grid_max[0:2])
    newline_max[1] += max(grid_max[0:3])
    newline_max[2] += max(grid_max[1:3])
    grid_max = newline_max[:]
    newline_min[0] += min(grid_min[0:2])
    newline_min[1] += min(grid_min[0:3])
    newline_min[2] += min(grid_min[1:3])
    grid_min = newline_min[:]

print(max(grid_max), min(grid_min))