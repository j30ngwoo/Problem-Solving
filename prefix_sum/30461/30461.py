import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, m, q = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]

    for x in range(m):
        for y in range(1, n):
            grid[y][x] += grid[y - 1][x]
    
    for start_y in range(n):
        x = 1
        y = start_y + 1
        while x < m and y < n:
            grid[y][x] += grid[y - 1][x - 1]
            x += 1
            y += 1

    for start_x in range(1, m):
        x = start_x + 1
        y = 1
        while x < m and y < n:
            grid[y][x] += grid[y - 1][x - 1]
            x += 1
            y += 1
    
    for _ in range(q):
        w, p = map(int, input().split())
        print(grid[w - 1][p - 1])

if __name__ == "__main__":
    main()
