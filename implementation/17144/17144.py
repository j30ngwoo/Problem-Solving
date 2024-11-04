import sys
input = lambda: sys.stdin.readline().strip()

def main():
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    h, w, t = map(int, input().split())
    grid = []
    for _ in range(h):
        grid.append(list(map(int, input().split())))

    cleaner_upper_y = None
    cleaner_lower_y = None
    for y in range(h):
        for x in range(w):
            if grid[y][x] == -1:
                if not cleaner_upper_y:
                    cleaner_upper_y = y
                else:
                    cleaner_lower_y = y

    for _ in range(t):
        delta = [[0 for _ in range(w)] for _ in range(h)]
        for y in range(h):
            for x in range(w):
                if grid[y][x] >= 5:
                    spread = grid[y][x] // 5
                    for i in range(4):
                        next_x = x + dx[i]
                        next_y = y + dy[i]
                        if 0 <= next_x < w and 0 <= next_y < h and grid[next_y][next_x] != -1:
                            delta[next_y][next_x] += spread
                            delta[y][x] -= spread
        for y in range(h):
            for x in range(w):
                grid[y][x] += delta[y][x]
        
        for y in range(cleaner_upper_y - 1, 0, -1):
            grid[y][0] = grid[y - 1][0]
        for x in range(w - 1):
            grid[0][x] = grid[0][x + 1]
        for y in range(cleaner_upper_y):
            grid[y][w - 1] = grid[y + 1][w - 1]
        for x in range(w - 1, 1, -1):
            grid[cleaner_upper_y][x] = grid[cleaner_upper_y][x - 1]
        grid[cleaner_upper_y][1] = 0

        for y in range(cleaner_lower_y + 1, h - 1):
            grid[y][0] = grid[y + 1][0]
        for x in range(w - 1):
            grid[h - 1][x] = grid[h - 1][x + 1]
        for y in range(h - 1, cleaner_lower_y, -1):
            grid[y][w - 1] = grid[y - 1][w - 1]
        for x in range(w - 1, 1, -1):
            grid[cleaner_lower_y][x] = grid[cleaner_lower_y][x - 1]
        grid[cleaner_lower_y][1] = 0

    print(sum([sum(row) for row in grid]) + 2)

if __name__ == "__main__":
    main()