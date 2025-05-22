import sys
input = lambda: sys.stdin.readline().rstrip()
from collections import deque
from copy import deepcopy

DY, DX = [0, 0, -1, 1], [-1, 1, 0, 0]

def is_avail(y, x):
    return grid[y][x] == '.' or grid[y][x] == '$' or grid[y][x].islower() or grid[y][x] in keys

def solve():
    global grid, keys
    h, w = map(int, input().split())
    grid = [list(input()) for _ in range(h)]
    keys = set(input().upper())
    prev_visit = None
    result = 0
    
    while True:
        visit = [[False for _ in range(w)] for _ in range(h)]
        
        q = deque()
        for y in range(h):
            if is_avail(y, 0):
                q.append((y, 0))
            if is_avail(y, w - 1):
                q.append((y, w - 1))
        for x in range(1, w - 1):
            if is_avail(0, x):
                q.append((0, x))
            if is_avail(h - 1, x):
                q.append((h - 1, x))

        while q:
            y, x = q.popleft()
            if visit[y][x]:
                continue
            visit[y][x] = True

            if grid[y][x].islower():
                keys.add(grid[y][x].upper())
            
            if grid[y][x].isupper():
                grid[y][x] = '.'
            
            if grid[y][x] == '$':
                result += 1
                grid[y][x] = '.'
            
            for d in range(4):
                ny, nx = y + DY[d], x + DX[d]
                if 0 <= ny < h and 0 <= nx < w and is_avail(ny, nx):
                    q.append((ny, nx))
        

        if prev_visit == visit:
            break
        prev_visit = visit
    
    print(result)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
