import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n, a, b = map(int, input().split())
    grid = [list(input()) for _ in range(n)]
    stars = [[0 for _ in range(n)] for _ in range(n)]

    # B부터
    for y in range(n):
        for x in range(n):
            py, px = y - b, x - a
            if grid[y][x] == "B":
                if 0 <= py < n and 0 <= px < n and (grid[py][px] == "B" or grid[py][px] == "G"):
                    stars[py][px] = stars[y][x] = 1
                else:
                    return -1
            
    for y in range(n):
        for x in range(n):
            py, px = y - b, x - a
            if grid[y][x] == "G" and not stars[y][x]:
                if not (0 <= py < n and 0 <= px < n) or 0 <= py < n and 0 <= px < n and not stars[py][px]:
                    stars[y][x] = 1

    return sum(map(sum, stars))

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

main()