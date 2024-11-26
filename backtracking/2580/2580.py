import sys
input = lambda: sys.stdin.readline().strip()

def main():
    grid = []
    for _ in range(9):
        grid.append(list(map(int, input().split())))

    coords = [] # x, y
    for y in range(9):
        for x in range(9):
            if grid[y][x] == 0:
                coords.append((x, y))

    def recursion(coords_i):
        if coords_i == len(coords):
            print('\n'.join(map(lambda row: ' '.join(map(str, row)), grid)))
            exit(0)
        
        x = coords[coords_i][0]
        y = coords[coords_i][1]

        available_nums = set((1, 2, 3, 4, 5, 6, 7, 8, 9))
        for dx in range(9):
            available_nums.discard(grid[y][dx])
        for dy in range(9):
            available_nums.discard(grid[dy][x])
        start_y = (y // 3) * 3
        start_x = (x // 3) * 3
        for dy in range(start_y, start_y + 3):
            for dx in range(start_x, start_x + 3):
                available_nums.discard(grid[dy][dx])

        for i in available_nums:
            grid[y][x] = i
            recursion(coords_i + 1)
            grid[y][x] = 0

    recursion(0)

if __name__ == "__main__":
    main()
