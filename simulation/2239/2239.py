import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    grid = [list(map(int, list(input()))) for _ in range(9)]
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    blocks = [set() for _ in range(9)]

    def get_block_index(y, x):
        return (y // 3) * 3 + (x // 3)

    for y in range(9):
        for x in range(9):
            if grid[y][x] != 0:
                rows[y].add(grid[y][x])
                cols[x].add(grid[y][x])
                blocks[get_block_index(y, x)].add(grid[y][x])

    def backtracking(y, x):
        if x == 9:
            x = 0
            y += 1
        
        if y == 9:
            print('\n'.join(map(lambda row: ''.join(map(str, row)), grid)))
            exit(0)

        if grid[y][x] == 0:
            for i in range(1, 10):
                if (i in rows[y]) or (i in cols[x]) or (i in blocks[get_block_index(y, x)]):
                    continue
                grid[y][x] = i
                rows[y].add(grid[y][x])
                cols[x].add(grid[y][x])
                blocks[get_block_index(y, x)].add(grid[y][x])
                backtracking(y, x + 1)
                rows[y].discard(grid[y][x])
                cols[x].discard(grid[y][x])
                blocks[get_block_index(y, x)].discard(grid[y][x])
            grid[y][x] = 0
        else:
            backtracking(y, x + 1)

    backtracking(0, 0)

if __name__ == "__main__":
    main()
