import sys
input = lambda: sys.stdin.readline().strip()
from itertools import combinations

n, m = map(int, input().split())
grid = []
for _ in range(n):
    grid.append(tuple(map(int, input().split())))

chick_coords = []
house_coords = []
for y in range(n):
    for x in range(n):
        if grid[y][x] == 1:
            house_coords.append((x, y))
        elif grid[y][x] == 2:
            chick_coords.append((x, y))

def get_chick_dist():
    total_dist = 0
    for house_x, house_y in house_coords:
        dist = float('inf')
        for chick_x, chick_y in comb:
            dist = min(dist, abs(house_x - chick_x) + abs(house_y - chick_y))
        total_dist += dist
    return total_dist

result = float('inf')
for comb in combinations(chick_coords, m):
    result = min(result, get_chick_dist())
print(result)