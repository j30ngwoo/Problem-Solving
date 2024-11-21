import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

# (y, x)로 통일

def main():
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    n, l, r = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]

    def bfs(y, x):
        alliance_coords = set()
        q = deque([(y, x)])
        total_people = 0
        while q:
            now_y, now_x = q.popleft()
            if is_visitied[now_y][now_x]:
                continue
            is_visitied[now_y][now_x] = True
            alliance_coords.add((now_y, now_x))
            total_people += grid[now_y][now_x]

            for d in range(4):
                next_x = now_x + dx[d]
                next_y = now_y + dy[d]
                if not (0 <= next_x < n and 0 <= next_y < n) or is_visitied[next_y][next_x]:
                    continue
                if l <= abs(grid[next_y][next_x] - grid[now_y][now_x]) <= r:
                    q.append((next_y, next_x))

        if len(alliance_coords) <= 1:
            return False
        
        new_people = int(total_people / len(alliance_coords))
        for coord in alliance_coords:
            grid[coord[0]][coord[1]] = new_people

        return True


    result = 0
    while True:
        is_visitied = [[False for _ in range(n)] for _ in range(n)]

        is_there_alliance = False
        for y in range(n):
            for x in range(n):
                if bfs(y, x):
                    is_there_alliance = True

        if is_there_alliance:
            result += 1
        else:
            break
    
    print(result)

if __name__ == "__main__":
    main()
