import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    r, c, k = map(int, input().split())
    r, c = r - 1, c - 1
    max_r, max_c = 3, 3
    grid = [list(map(int, input().split())) for _ in range(3)]

    def reverse(grid):
        new_grid = [[] for _ in range(len(grid[0]))]
        for y in range(len(grid[0])):
            for x in range(len(grid)):
                new_grid[y].append(grid[x][y])
        return new_grid

    result = 0
    while not (r < max_r and c < max_c and grid[r][c] == k):
        if result > 100:
            print(-1)
            return
        result += 1

        is_reversed = False
        if max_r < max_c:
            is_reversed = True
            grid = reverse(grid)
            max_r, max_c = max_c, max_r

        new_grid = []
        for row in grid:
            d = dict()
            for elem in row:
                if elem == 0:
                    continue
                if elem in d:
                    d[elem] += 1
                else:
                    d[elem] = 1
            new_row = []
            for key_value in sorted(list(d.items()), key=lambda x: (x[1], x[0])):
                new_row += key_value
            new_grid.append(new_row)
        grid = new_grid

        max_c = min(max(len(row) for row in grid), 100)
        for row in grid:
            if len(row) > 100:
                row = row[:100]
            if len(row) < max_c:
                row += [0] * (max_c - len(row))

        if is_reversed:
            grid = reverse(grid)
            max_r, max_c = max_c, max_r
    
    print(result)

if __name__ == "__main__":
    main()
