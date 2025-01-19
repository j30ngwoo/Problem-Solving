import sys
input = lambda: sys.stdin.readline().rstrip()
from itertools import combinations
from collections import deque
from copy import deepcopy

T = 2
DY = [0, 0, -1, 1]
DX = [-1, 1, 0, 0]


def main():
    n, m = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    virus_coords = [(y, x) for x in range(n) for y in range(n) if grid[y][x] == 2]
    
    def get_time(virus_combs):
        max_time = 0
        temp_grid = deepcopy(grid)
        q = deque()
        for virus_coord in virus_combs:
            q.append(virus_coord + tuple([0]))
        
        while q:
            y, x, time = q.popleft()
            if temp_grid[y][x] == 1:
                continue
            if temp_grid[y][x] == 0:
                max_time = max(time, max_time)
            temp_grid[y][x] = 1

            for d in range(4):
                next_y = y + DY[d]
                next_x = x + DX[d]
                if 0 <= next_x < n and 0 <= next_y < n and temp_grid[next_y][next_x] != 1:
                    q.append((next_y, next_x, time + 1))

        # print(virus_combs)
        # print('\n'.join(map(str, temp_grid)))
        # print(max_time)
        # print('-----------------------------')
        if all(e != 0 for row in temp_grid for e in row):
            return max_time
        else:
            return float('inf')


    result = float('inf')
    for combs in combinations(virus_coords, m):
        result = min(result, get_time(combs))

    if result == float('inf'):
        print(-1)
    else:
        print(result)


if __name__ == "__main__":
    main()
