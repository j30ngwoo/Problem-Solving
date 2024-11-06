import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque
from copy import deepcopy

def main():
    n, m = map(int, input().split())
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))

    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    result = 0
    while sum([sum(row) for row in grid]) > 0:
        result += 1
        temp_grid = deepcopy(grid)
        visited = [[False for _ in range(m)] for _ in range(n)]
        q = deque([[0, 0]])
        while q:
            #print('\n'.join(map(str, visited)), '\n')
            now_x, now_y = q.popleft()
            #print(now_x, now_y)
            if temp_grid[now_y][now_x] >= 1:
                temp_grid[now_y][now_x] += 1
                continue
            if visited[now_y][now_x] and temp_grid[now_y][now_x] == 0:
                continue
            visited[now_y][now_x] = True

            for d in range(4):
                next_x = now_x + dx[d]
                next_y = now_y + dy[d]
                if 0 <= next_x < m and 0 <= next_y < n and not visited[next_y][next_x]:
                    q.append([next_x, next_y])

        for y in range(n):
            for x in range(m):
                if temp_grid[y][x] >= 3:
                    grid[y][x] = 0
    
    print(result)

if __name__ == "__main__":
    main()
