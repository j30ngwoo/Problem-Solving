import sys
input = lambda: sys.stdin.readline().rstrip()

DY = {'U':-1, 'D':1, 'L':0, 'R':0}
DX = {'U':0, 'D':0, 'L':-1, 'R':1}

def main():
    n, m = map(int, input().split())
    grid = [list(input()) for _ in range(n)]
    is_visited = [[False for _ in range(m)] for _ in range(n)]
    result = 0

    def dfs(y, x):
        nonlocal result
        if is_visited[y][x]:
            if (y, x) in currents:
                result += 1
            return
        is_visited[y][x] = True
        currents.add((y, x))
        dir = grid[y][x]
        dfs(y + DY[dir], x + DX[dir])

    for sy in range(n):
        for sx in range(m):
            currents = set()
            dfs(sy, sx)

    print(result)

main()