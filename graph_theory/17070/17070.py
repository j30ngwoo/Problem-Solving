import sys
input = lambda: sys.stdin.readline().strip()

#x, y
HORIZONTAL = (1, 0)
DIAGONAL = (1, 1)
VERTICAL = (0, 1)

n = int(input())
grid = []
for _ in range(n):
    grid.append(list(map(int, input().split())))

result = 0

def recursion(x, y, now_state):
    global result
    if x >= n or y >= n:
        return
    if now_state == DIAGONAL and (grid[y - 1][x] == 1 or grid[y][x - 1] == 1):
        return
    if grid[y][x] == 1:
        return
    if x == n - 1 and y == n - 1:
        result += 1
        return
    for next_state in (HORIZONTAL, DIAGONAL, VERTICAL):
        if (now_state == HORIZONTAL and next_state == VERTICAL) or (now_state == VERTICAL and next_state == HORIZONTAL):
            continue
        recursion(x + next_state[0], y + next_state[1], next_state)

if grid[n - 1][n - 1] == 0:
    recursion(1, 0, HORIZONTAL)
print(result)