import sys
input = lambda: sys.stdin.readline().strip()
from copy import deepcopy

N, E, S, W = 0, 1, 2, 3
Y, X, V = 0, 1, 2

def main():
    n = int(input())
    grid = [list(map(int, input().split())) for _ in range(n)]


    def rotate_counterclock():
        nonlocal grid

        rotated = [[0 for _ in range(n)] for _ in range(n)]
        for y in range(n):
            for x in range(n):
                rotated[n - 1 - x][y] = grid[y][x]
        grid = rotated

    result = max(max(row) for row in grid)


    def move(direction):
        nonlocal result, grid

        for _ in range(direction):
            rotate_counterclock()
        
        for x in range(n):
            up_y = 0
            for y in range(1, n):
                if grid[y][x] == 0:
                    continue
                if grid[y][x] == grid[up_y][x]:
                    grid[up_y][x] *= 2
                    result = max(result, grid[up_y][x])
                    up_y += 1
                    grid[y][x] = 0
                else:
                    if grid[up_y][x] != 0:
                        up_y += 1
                    grid[up_y][x], grid[y][x] = grid[y][x], grid[up_y][x]
    
        for _ in range((4 - direction) % 4):
            rotate_counterclock()


    def recurison(depth):
        nonlocal grid

        if depth == 5:
            return
        for direction in N, E, S, W:
            temp = deepcopy(grid)
            move(direction)
            recurison(depth + 1)
            grid = temp
    
    
    recurison(0)
    print(result)


if __name__ == "__main__":
    main()
