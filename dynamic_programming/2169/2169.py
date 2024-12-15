import sys
input = lambda: sys.stdin.readline().strip()
from copy import deepcopy

def main():
    n, m = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    
    # row 0
    for x in range(1, m):
        grid[0][x] += grid[0][x - 1]
    
    # row 1 ~ (n - 2)
    for y in range(1, n - 1):
        from_left = grid[y][:]
        from_left[0] += grid[y - 1][0]
        for x in range(1, m):
            from_left[x] += max(from_left[x - 1], grid[y - 1][x])

        from_right = grid[y][:]
        from_right[m - 1] += grid[y - 1][m - 1]
        for x in range(m - 2, -1, -1):
            from_right[x] += max(from_right[x + 1], grid[y - 1][x])

        grid[y] = [max(from_left[x], from_right[x]) for x in range(m)]

    # row n - 1
    if n > 1:
        grid[n - 1][0] += grid[n - 2][0]
        for x in range(1, m):
            grid[n - 1][x] += max(grid[n - 1][x - 1], grid[n - 2][x])

    print(grid[n - 1][m - 1])


if __name__ == "__main__":
    main()
