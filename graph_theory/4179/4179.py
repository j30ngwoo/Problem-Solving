import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque
from copy import deepcopy

MAX = 10000

def main():
    DX = [0, 0, 1, -1]
    DY = [1, -1, 0, 0]

    R, C = map(int, input().split())
    grid = []
    for _ in range(R):
        grid.append(list(input()))
    
    jihun_coord = None
    fire_coords = []
    for y in range(R):
        for x in range(C):
            if grid[y][x] == 'J':
                jihun_coord = [y, x]
                grid[y][x] = MAX
            elif grid[y][x] == 'F':
                fire_coords.append([y, x])
                grid[y][x] = MAX
            elif grid[y][x] == '.':
                grid[y][x] = MAX

    exits = []
    j_grid = deepcopy(grid)
    q = deque()
    q.append(jihun_coord + [0])
    while q:
        y, x, count = q.popleft()
        if j_grid[y][x] != MAX:
            continue
        j_grid[y][x] = count
        if y == 0 or y == R - 1 or x == 0 or x == C - 1:
            exits.append([y, x])

        for d in range(4):
            next_y = y + DY[d]
            next_x = x + DX[d]
            if 0 <= next_y < R and 0 <= next_x < C and j_grid[next_y][next_x] == MAX:
                q.append((next_y, next_x, count + 1))

    f_grid = deepcopy(grid)
    q = deque()
    for fire_coord in fire_coords:
        q.append(fire_coord + [0])
    while q:
        y, x, count = q.popleft()
        if f_grid[y][x] != MAX:
            continue
        f_grid[y][x] = count

        for d in range(4):
            next_y = y + DY[d]
            next_x = x + DX[d]
            if 0 <= next_y < R and 0 <= next_x < C and f_grid[next_y][next_x] == MAX:
                q.append((next_y, next_x, count + 1))
    
    min_count = float('inf')
    for y, x in exits:
        if j_grid[y][x] < f_grid[y][x]:
            min_count = min(min_count, j_grid[y][x] + 1)
    
    if min_count == float('inf'):
        print('IMPOSSIBLE')
    else:
        print(min_count)


if __name__ == "__main__":
    main()
