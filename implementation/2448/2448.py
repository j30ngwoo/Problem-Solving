import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
grid = [list(" " * (n * 2 - 1)) for _ in range(n + 1)]

def recursion(x, y, layer):
    if layer == 3:
        grid[y][x] = '*'
        grid[y + 1][x - 1] = '*'
        grid[y + 1][x + 1] = '*'
        grid[y + 2][x - 2] = '*'
        grid[y + 2][x - 1] = '*'
        grid[y + 2][x] = '*'
        grid[y + 2][x + 1] = '*'
        grid[y + 2][x + 2] = '*'
        return
    recursion(x, y, layer // 2)
    recursion(x - layer // 2, y + layer // 2, layer // 2)
    recursion(x + layer // 2, y + layer // 2, layer // 2)

recursion(n - 1, 0, n)

for s in grid:
    print(''.join(s))
