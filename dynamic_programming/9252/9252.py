import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    a, b = ' ' + input(), ' ' + input()

    grid = [[0 for _ in range(len(a))] for _ in range(len(b))]
    for x in range(1, len(a)):
        for y in range(1, len(b)):
            if a[x] == b[y]:
                grid[y][x] = grid[y - 1][x - 1] + 1
            else:
                grid[y][x] = max(grid[y][x - 1], grid[y - 1][x])

    if grid[-1][-1] == 0:
        print(0)
        return

    result = ''
    x, y = len(a) - 1, len(b) - 1
    while x > 0 and y > 0:
        if grid[y][x] == grid[y - 1][x]:
            y -= 1
        elif grid[y][x] == grid[y][x - 1]:
            x -= 1
        else:
            result += a[x]
            x, y = x - 1, y - 1

    print(grid[-1][-1])
    print(result[::-1])

if __name__ == "__main__":
    main()
