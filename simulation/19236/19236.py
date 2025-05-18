import sys
input = lambda: sys.stdin.readline().strip()
from copy import deepcopy

DY = [-1, -1, 0, 1, 1, 1, 0, -1]
DX = [0, -1, -1, -1, 0, 1, 1, 1]
Y, X = 0, 1
N, D = 0, 1

def main():
    grid = list(map(lambda l: [[l[i], l[i + 1] - 1] for i in range(0, 8, 2)], [list(map(int, input().split())) for _ in range(4)]))
    fishs = [None] * 17 # Y, X, D
    for y in range(4):
        for x in range(4):
            fishs[grid[y][x][N]] = [y, x]
    
    shark_d = grid[0][0][D]
    sum = grid[0][0][N]
    fishs[grid[0][0][N]] = None
    grid[0][0] = None
    result = sum

    def recursion(y, x, d, sum, grid, fishs):
        nonlocal result
        for fish in fishs:
            if not fish:
                continue
            #print('위치:', fish)
            for i in range(8):
                fish_nd = (grid[fish[Y]][fish[X]][D] + i) % 8
                fish_ny, fish_nx = fish[Y] + DY[fish_nd], fish[X] + DX[fish_nd]
                #print(fish[Y], fish[X])
                if 0 <= fish_ny < 4 and 0 <= fish_nx < 4 and (fish_ny, fish_nx) != (y, x):
                    #print('변환 시작')
                    grid[fish[Y]][fish[X]][D] = fish_nd
                    #print(fish[Y], fish[X])
                    if grid[fish_ny][fish_nx] == None:
                        fishs[grid[fish[Y]][fish[X]][N]] = [fish_ny, fish_nx]
                        grid[fish_ny][fish_nx] = grid[fish[Y]][fish[X]]
                        grid[fish[Y]][fish[X]] = None
                    else:
                        grid[fish[Y]][fish[X]], grid[fish_ny][fish_nx] = grid[fish_ny][fish_nx], grid[fish[Y]][fish[X]]
                        fishs[grid[fish[Y]][fish[X]][N]], fishs[grid[fish_ny][fish_nx][N]] = fishs[grid[fish_ny][fish_nx][N]], fishs[grid[fish[Y]][fish[X]][N]]
                    break
                
        while True:
            next_grid, next_fishs = deepcopy(grid), deepcopy(fishs)
            y, x = y + DY[d], x + DX[d]
            if not (0 <= y < 4 and 0 <= x < 4):
                break
            if not next_grid[y][x]:
                continue
            next_d = next_grid[y][x][D]
            next_sum = sum + next_grid[y][x][N]
            result = max(next_sum, result)
            next_fishs[next_grid[y][x][N]] = None
            next_grid[y][x] = None
            # for i in range(17):
            #     print(i, ':', fishs[i])
            # print('\n'.join(map(str, grid)), '\n--------------')
            recursion(y, x, next_d, next_sum, next_grid, next_fishs)

    recursion(0, 0, shark_d, sum, grid, fishs)

    print(result)

main()
