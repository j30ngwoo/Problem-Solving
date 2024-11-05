import sys
input = lambda: sys.stdin.readline().strip()
import heapq

def main():
    dx = [0, -1, 1, 0]
    dy = [-1, 0, 0, 1]

    n = int(input())
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    
    for y in range(n):
        for x in range(n):
            if grid[y][x] == 9:
                baby_x, baby_y = x, y
                grid[y][x] = 0
    
    visited = [[False for _ in range(n)] for _ in range(n)]
    pq = [[0, baby_y, baby_x]] # 우선순위: dist, y, x
    size = 2
    eat = 0
    total_dist = 0
    while pq:
        now_dist, now_y, now_x = heapq.heappop(pq)
        if visited[now_y][now_x]:
            continue
        visited[now_y][now_x] = True

        if 0 < grid[now_y][now_x] < size:
            grid[now_y][now_x] = 0
            total_dist = now_dist
            visited = [[False for _ in range(n)] for _ in range(n)]
            pq = []
            eat += 1
            if eat == size:
                size += 1
                eat = 0
        
        for d in range(4):
            next_x = now_x + dx[d]
            next_y = now_y + dy[d]
            if 0 <= next_x < n and 0 <= next_y < n and not visited[next_y][next_x] and grid[next_y][next_x] <= size:
                heapq.heappush(pq, [now_dist + 1, next_y, next_x])

    print(total_dist)

if __name__ == "__main__":
    main()
