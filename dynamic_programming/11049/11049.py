import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    mats = [list(map(int, input().split())) for _ in range(n)]
    min_table = [[0 if y == x else float('inf') for y in range(n)] for x in range(n)]

    def set_min(ty, tx):
        for x1 in range(ty, tx):
            y2 = x1 + 1
            value = min_table[ty][x1] + min_table[y2][tx] + mats[ty][0] * mats[x1][1] * mats[tx][1]
            min_table[ty][tx] = min(min_table[ty][tx], value)

    for diff in range(1, n):
        for x in range(diff, n):
            y = x - diff
            set_min(y, x)
    
    print(min_table[0][n - 1])

if __name__ == "__main__":
    main()
