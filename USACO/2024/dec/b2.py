import sys
input = lambda: sys.stdin.readline().rstrip()

X, Y, Z = 0, 1, 2

def main():
    n, q = map(int, input().split())
    result = 0
    counts = [[[n for _ in range(n)] for _ in range(n)] for _ in range(3)]

    for _ in range(q):
        x, y, z = map(int, input().split())
        counts[X][y][z] -= 1
        if counts[X][y][z] == 0:
            result += 1
        counts[Y][z][x] -= 1
        if counts[Y][z][x] == 0:
            result += 1
        counts[Z][x][y] -= 1
        if counts[Z][x][y] == 0:
            result += 1
        print(result)

main()