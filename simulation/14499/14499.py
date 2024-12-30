import sys
input = lambda: sys.stdin.readline().strip()

E = 1
W = 2
N = 3
S = 4

TOP = 1
BOTTOM = 6

DY = [0, 0, 0, -1, 1]
DX = [0, 1, -1, 0, 0]

def main():
    n, m, y, x, k = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(n)]
    opers = list(map(int, input().split()))
    dice = [0, 0, 0, 0, 0, 0, 0]
    

    def rotate_dice(d):
        nonlocal dice

        if d == E:
            dice[1], dice[3], dice[6], dice[4] = dice[4], dice[1], dice[3], dice[6]
        elif d == W:
            dice[1], dice[3], dice[6], dice[4] = dice[3], dice[6], dice[4], dice[1]
        elif d == N:
            dice[1], dice[5], dice[6], dice[2] = dice[5], dice[6], dice[2], dice[1]
        else:
            dice[1], dice[5], dice[6], dice[2] = dice[2], dice[1], dice[5], dice[6]


    def copy_dice():
        nonlocal y, x
        
        if grid[y][x] == 0:
            grid[y][x] = dice[BOTTOM]
        else:
            dice[BOTTOM] = grid[y][x]
            grid[y][x] = 0


    for oper in opers:
        next_y, next_x = y + DY[oper], x + DX[oper]
        if not (0 <= next_y < n and 0 <= next_x < m):
            continue
        y, x = next_y, next_x
        rotate_dice(oper)
        copy_dice()
        print(dice[TOP])

if __name__ == "__main__":
    main()
