import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

dx = (1, -1, 0, 0)
dy = (0, 0, 1, -1)

h, w = map(int, input().split())
grid = []
for _ in range(h):
    grid.append(list(map(int, input().split())))

count = 0
s = 0
while sum([sum(row) for row in grid]) > 0:
    s = sum([sum(row) for row in grid])
    visited = [[False for _ in range(w)] for _ in range(h)]
    q = deque()
    q.append((0, 0))

    while q:
        now_x, now_y = q.pop()
        if visited[now_y][now_x]:
            continue
        visited[now_y][now_x] = True

        if grid[now_y][now_x] == 1:
            grid[now_y][now_x] = 0
            continue

        for d in range(4):
            next_x = now_x + dx[d]
            next_y = now_y + dy[d]
            if (0 <= next_x < w) and (0 <= next_y < h) and not visited[next_y][next_x]:
                q.append((next_x, next_y))

    count += 1

print(count)
print(s)