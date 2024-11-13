import sys
input = lambda: sys.stdin.readline().strip()

N, E, S, W = 0, 1, 2, 3
Y, X = 0, 1
DELTAS = [(-1, 0), (0, 1), (1, 0), (0, -1)] # (DY, DX)

def main():
    n, _ = map(int, input().split())
    r, c, forward = map(int, input().split())
    cleaner = [r, c] # Y, X
    grid = [list(map(int, input().split())) for _ in range(n)]
    
    result = 0
    while True:
        now_x = cleaner[X]
        now_y = cleaner[Y]
        if grid[now_y][now_x] == 0:
            grid[now_y][now_x] = 2 # cleaned <- 2
            result += 1
        
        is_there_blank = False
        for i in range(4):
            next_x = now_x + DELTAS[i][X]
            next_y = now_y + DELTAS[i][Y]
            if grid[next_y][next_x] == 0:
                is_there_blank = True

        if not is_there_blank:
            backward = (forward + 2) % 4
            next_x = now_x + DELTAS[backward][X]
            next_y = now_y + DELTAS[backward][Y]
            if grid[next_y][next_x] == 1:
                break
            else:
                cleaner = [next_y, next_x]
        else:
            forward = (forward - 1) % 4
            next_x = now_x + DELTAS[forward][X]
            next_y = now_y + DELTAS[forward][Y]
            if grid[next_y][next_x] == 0:
                cleaner = [next_y, next_x]
    
    print(result)

if __name__ == "__main__":
    main()
