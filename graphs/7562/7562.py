import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import deque

DX = (1, 2, 2, 1, -1, -2, -2, -1)
DY = (-2, -1, 1, 2, 2, 1, -1, -2)

def solve():
    l = int(input())
    is_visited = [[False for _ in range(l)] for _ in range(l)]
    x1, y1 = map(int, input().split())
    x2, y2 = map(int, input().split())

    q = deque([(y1, x1, 0)])
    while q:
        y, x, cnt = q.popleft()
        if y == y2 and x == x2:
            print(cnt)
            break
        if is_visited[y][x]:
            continue
        is_visited[y][x] = True
        for d in range(8):
            ny, nx = y + DY[d], x + DX[d]
            if ny < 0 or l <= ny or nx < 0 or l <= nx or is_visited[ny][nx]:
                continue
            q.append((ny, nx, cnt + 1))

def main():
    tc = int(input())
    for _ in range(tc):
        solve()

main()