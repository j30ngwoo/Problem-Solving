import sys
input = lambda: sys.stdin.readline().rstrip()
from itertools import combinations
from collections import deque
from copy import deepcopy

DELTAS = [[0, -1], [-1, 0], [0, 1]]

def main():
    n, m, d = map(int, input().split())
    origin_grid = [list(map(int, input().split())) for _ in range(n)]

    result = 0
    for archers_x in combinations(range(m), 3):
        grid = deepcopy(origin_grid)
        total_deleted = 0
        for remain in range(n - 1, -1, -1):
            deleted_set = set()
            for archer_x in archers_x:
                q = deque([(remain, archer_x, 1)])
                is_visited = [[False for _ in range(m)] for _ in range(remain + 1)]
                while q:
                    y, x, dist = q.popleft()
                    if grid[y][x] == 1:
                        deleted_set.add((y, x))
                        break
                    for dy, dx in DELTAS:
                        next_y = y + dy
                        next_x = x + dx
                        if dist < d and 0 <= next_y and 0 <= next_x < m and not is_visited[next_y][next_x]:
                            is_visited[next_y][next_x] = True
                            q.append((next_y, next_x, dist + 1))
            total_deleted += len(deleted_set)
            for y, x in deleted_set:
                grid[y][x] = 0
            grid.pop()
        result = max(result, total_deleted)
    print(result)

if __name__ == "__main__":
    main()
