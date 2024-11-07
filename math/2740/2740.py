import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, m = map(int, input().split())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))

    m, k = map(int, input().split())
    b = []
    for _ in range(m):
        b.append(list(map(int, input().split())))

    result = [[None for _ in range(k)] for _ in range(n)]
    for y in range(n):
        for x in range(k):
            result[y][x] = sum(a[y][i] * b[i][x] for i in range(m))

    for row in result:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()
