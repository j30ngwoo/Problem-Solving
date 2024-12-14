import sys
input = lambda: sys.stdin.readline().strip()
from copy import deepcopy

N, E, S, W = [-1, 0], [0, 1], [1, 0], [0, -1]

DIRECS = [
    [],
    [[N], [E], [S], [W]],
    [[N, S], [E, W]],
    [[N, E], [E, S], [S, W], [W, N]],
    [[N, E, S], [E, S, W], [S, W, N], [W, N, E]],
    [[N, E, S, W]],
]

Y = 0
X = 1
TYPE = 2

def main():
    n, m = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    
    cctvs = [] # Y, X, TYPE
    for y in range(n):
        for x in range(m):
            if 1 <= grid[y][x] <= 5:
                cctvs.append([y, x, grid[y][x]])
                grid[y][x] = '#'
    
    result = float('inf')

    def recursion(cctv_index):
        nonlocal result, grid
        if cctv_index == len(cctvs):
            #print('\n'.join(map(str, grid)), '\n-------------------')
            result = min(result, sum(grid[row].count(0) for row in range(n)))
            return
        y, x, type = cctvs[cctv_index]
        for directions in DIRECS[type]:
            original_grid = deepcopy(grid)
            for direction in directions:
                temp_y, temp_x = y, x
                while 0 <= temp_y < n and 0 <= temp_x < m and grid[temp_y][temp_x] != 6:
                    grid[temp_y][temp_x] = '#'
                    temp_y += direction[Y]
                    temp_x += direction[X]
            recursion(cctv_index + 1)
            grid = original_grid


    recursion(0)
    print(result)

if __name__ == "__main__":
    main()
