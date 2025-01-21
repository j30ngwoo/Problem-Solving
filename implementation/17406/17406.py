import sys
input = lambda: sys.stdin.readline().rstrip()
from copy import deepcopy
from itertools import permutations

INIT_Y = [-1, -1, 1, 1]
INIT_X = [-1, 1, 1, -1]
DY = [0, 1, 0, -1]
DX = [1, 0, -1, 0]


def turn(grid, r, c, s):
    new_grid = deepcopy(grid)
    
    for radius in range(1, s + 1):
        for d in range(4):
            y = r + radius * INIT_Y[d]
            x = c + radius * INIT_X[d]
            for _ in range(radius * 2):
                next_y, next_x = y + DY[d], x + DX[d]
                new_grid[next_y][next_x] = grid[y][x]
                y, x = next_y, next_x
    
    return new_grid


def get_value(grid, oper_perm):
    for oper in oper_perm:
        r, c, s = oper
        grid = turn(grid, r - 1, c - 1, s)

    return min(sum(row) for row in grid)


def main():
    n, m, k = map(int, input().split())
    orignal = [list(map(int, input().split())) for _ in range(n)]
    opers = [list(map(int, input().split())) for _ in range(k)]

    result = float('inf')
    for oper_perm in permutations(opers):
        grid = deepcopy(orignal)
        result = min(result, get_value(grid, oper_perm))
    
    print(result)


if __name__ == "__main__":
    main()
