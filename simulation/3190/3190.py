import sys
input = lambda: sys.stdin.readline().strip()
import copy

X = 0
Y = 1
RIGHT = 0
DOWN = 1
LEFT = 2
UP = 3
DELTA = [(1, 0), (0, 1), (-1, 0), (0, -1)] # (DX, DY)

def main():
    n = int(input())
    k = int(input())
    apples = set()
    for _ in range(k):
        coord = list(map(int, input().split()))
        apples.add((coord[1], coord[0])) # [X, Y]
    l = int(input())
    table = dict()
    for _ in range(l):
        sec, turn = input().split()
        table[int(sec)] = turn # {time: turn}

    grid = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    grid[1][1] = 1
    head_direction = RIGHT
    tail_direction = RIGHT
    head = [1, 1] # [Y, X]
    tail = [1, 1]
    length = 1
    time = 0
    while True:
        head[X] += DELTA[head_direction][X]
        head[Y] += DELTA[head_direction][Y]
        time += 1
        if not (1 <= head[X] <= n and 1 <= head[Y] <= n and grid[head[Y]][head[X]] == 0):
            break

        grid[head[Y]][head[X]] = 1
        if tuple(head) in apples:
            apples.remove(tuple(head))
            length += 1
        else:
            grid[tail[Y]][tail[X]] = 0
            tail[X] += DELTA[tail_direction][X]
            tail[Y] += DELTA[tail_direction][Y]
        
        turn = table.get(time)
        if turn == 'L':
            head_direction = (head_direction - 1) % 4
        elif turn == 'D':
            head_direction = (head_direction + 1) % 4

        turn = table.get(time - length + 1)
        if turn == 'L':
            table[time - length + 1] = None
            tail_direction = (tail_direction - 1) % 4
        elif turn == 'D':
            table[time - length + 1] = None
            tail_direction = (tail_direction + 1) % 4

    print(time)

if __name__ == "__main__":
    main()
