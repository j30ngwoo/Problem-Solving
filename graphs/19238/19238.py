import sys
input = lambda: sys.stdin.readline().rstrip()
from heapq import heappop, heappush
from collections import deque

DY = [-1, 0, 0, 1]
DX = [0, -1, 1, 0]

def main():
    n, m, fuel = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    taxi_y, taxi_x = map(lambda x: int(x) - 1, input().split())
    guest = dict()
    for _ in range(m):
        y1, x1, y2, x2 = map(int, input().split())
        guest[(y1 - 1, x1 - 1)] = (y2 - 1, x2 - 1)

    while guest:
        # 태우러 가는 길
        is_complete = False
        pq = [(0, taxi_y, taxi_x)]
        is_visited = [[False for _ in range(n)] for _ in range(n)]
        goal = None
        while pq:
            dist, y, x = heappop(pq)
            if fuel < dist:
                print(-1)
                return
            
            if (y, x) in guest:
                taxi_y, taxi_x = y, x
                goal = guest[(y, x)]
                guest.pop((y, x))
                fuel -= dist
                is_complete = True
                break

            if is_visited[y][x]:
                continue
            is_visited[y][x] = True

            for d in range(4):
                next_y = y + DY[d]
                next_x = x + DX[d]
                if 0 <= next_y < n and 0 <= next_x < n and grid[next_y][next_x] != 1 and not is_visited[next_y][next_x]:
                    heappush(pq, (dist + 1, next_y, next_x))
        
        if not is_complete:
            print(-1)
            return

        # 목적지 가는 길
        is_complete = False
        q = deque([(0, taxi_y, taxi_x)])
        is_visited = [[False for _ in range(n)] for _ in range(n)]
        while q:
            dist, y, x = q.popleft()
            if fuel < dist:
                print(-1)
                return
            
            if (y, x) == goal:
                fuel += dist
                taxi_y, taxi_x = y, x
                is_complete = True
                break

            if is_visited[y][x]:
                continue
            is_visited[y][x] = True

            for d in range(4):
                next_y = y + DY[d]
                next_x = x + DX[d]
                if 0 <= next_y < n and 0 <= next_x < n and grid[next_y][next_x] != 1 and not is_visited[next_y][next_x]:
                    q.append((dist + 1, next_y, next_x))
        
        if not is_complete:
            print(-1)
            return

    print(fuel)

if __name__ == "__main__":
    main()
