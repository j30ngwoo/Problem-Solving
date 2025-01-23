import sys
input = lambda: sys.stdin.readline().rstrip()
from itertools import combinations 
from copy import deepcopy

DY = [0, 0, 1, -1]
DX = [1, -1, 0, 0]
Y = 0
X = 1

def main():
    n = int(input())
    grid = [list(input().split()) for _ in range(n)]
    spaces = []
    teachers = []
    for y in range(n):
        for x in range(n):
            if grid[y][x] == 'X':
                spaces.append((y, x))
            elif grid[y][x] == 'T':
                teachers.append((y, x))


    def can_avoid(space_comb):
        nonlocal teachers

        for space in space_comb:
            grid[space[Y]][space[X]] = 'O'
        for teacher in teachers:
            for d in range(4):
                y, x = teacher
                while 0 <= y < n and 0 <= x < n and grid[y][x] != 'O':
                    if grid[y][x] == 'S':
                        return False
                    y, x = y + DY[d], x + DX[d]
        
        return True


    for space_comb in combinations(spaces, 3):
        temp = deepcopy(grid)
        if can_avoid(space_comb):
            print('YES')
            return
        grid = temp
    
    print('NO')

if __name__ == "__main__":
    main()
