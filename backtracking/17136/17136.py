import sys
input = lambda: sys.stdin.readline().rstrip()
from copy import deepcopy

def main():
    def recursion(grid, papers):
        nonlocal result

        for y in range(10):
            for x in range(10):
                if not grid[y][x]:
                    continue
                for size in range(1, 6):
                    if papers[size] <= 0:
                        continue
                    max_y, max_x = y + size, x + size
                    if max_y > 10 or max_x > 10:
                        break
                    if not all(grid[next_y][next_x] == 1 for next_y in range(y, max_y) for next_x in range(x, max_x)):
                        break
                    temp_grid = deepcopy(grid)
                    temp_papers = deepcopy(papers)
                    for dy in range(size):
                        for dx in range(size):
                            temp_grid[y + dy][x + dx] = 0
                    temp_papers[size] -= 1
                    recursion(temp_grid, temp_papers)
                return
            
        result = min(result, 25 - sum(papers))

    grid = [list(map(int, input().split())) for _ in range(10)]

    result = float('inf')
    recursion(grid, [0, 5, 5, 5, 5, 5], 0)

    if result == float('inf'):
        print(-1)
    else:
        print(result)


if __name__ == "__main__":
    main()
