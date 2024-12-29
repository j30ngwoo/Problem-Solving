import sys
input = lambda: sys.stdin.readline().strip()
from heapq import heappop, heappush

DY = [0, 0, -1, 1]
DX = [-1, 1, 0, 0]

def main():
    w, h = map(int, input().split())
    grid = [input() for _ in range(h)]

    start = None
    end = None
    for y in range(h):
        for x in range(w):
            if grid[y][x] == 'C':
                if start == None:
                    start = (y, x)
                else:
                    end = (y, x)

    is_visited = [[False for _ in range(w)] for _ in range(h)]
    pq = [(0, start[0], start[1])]
    while pq:
        ref, y, x = heappop(pq)
        
        if (y, x) == end:
            print(ref - 1)
            break

        if is_visited[y][x]:
            continue
        is_visited[y][x] = True

        for d in range(4):
            next_x = x + DX[d]
            next_y = y + DY[d]
            while 0 <= next_x < w and 0 <= next_y < h and grid[next_y][next_x] != '*' and not is_visited[next_y][next_x]:
                heappush(pq, (ref + 1, next_y, next_x))
                next_x += DX[d]
                next_y += DY[d]
    
if __name__ == "__main__":
    main()
