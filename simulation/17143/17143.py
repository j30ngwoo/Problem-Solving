import sys
input = lambda: sys.stdin.readline().rstrip()

ROW = 0
COL = 1

SIZE = 2

UP, DOWN, RIGHT, LEFT = 1, 2, 3, 4
DR = [0, -1, 1, 0, 0]
DC = [0, 0, 0, 1, -1]

def main():
    R, C, M = map(int, input().split())
    sharks = dict()
    for _ in range(M):
        r, c, s, d, z = map(int, input().split())
        if d == UP or d == DOWN:
            sharks[(r, c)] = [s % ((R - 1) * 2), d, z]
        else:
            sharks[(r, c)] = [s % ((C - 1) * 2), d, z]

    def reverse(d):
        if d == UP:
            return DOWN
        if d == DOWN:
            return UP
        if d == RIGHT:
            return LEFT
        if d == LEFT:
            return RIGHT

    def get_next_pos(r, c, speed, direction):
        next_r = r + speed * DR[direction]
        next_c = c + speed * DC[direction]
        
        while next_r < 1 or R < next_r:
            direction = reverse(direction)
            if next_r < 1:
                next_r = 2 - next_r
            else: # R < next_r
                next_r = R - (next_r - R)
        
        while next_c < 1 or C < next_c:
            direction = reverse(direction)
            if next_c < 1:
                next_c = 2 - next_c
            else: # C < next_c
                next_c = C - (next_c - C)
        
        return next_r, next_c, direction


    result = 0
    for king in range(1, C + 1):
        catched = (float('inf'), 0)
        for r, c in sharks.keys():
            if c == king and r < catched[ROW]:
                catched = (r, c)
        if catched[ROW] != float('inf'):
            result += sharks[catched][SIZE]
            sharks.pop((catched))

        moved_sharks = dict()
        for r, c in sharks.keys():
            s, d, z = sharks[(r, c)]
            next_r, next_c, next_d = get_next_pos(r, c, s, d)
            next_coord = (next_r, next_c)
            if next_coord not in moved_sharks:
                moved_sharks[next_coord] = (s, next_d, z)
            elif moved_sharks[next_coord][SIZE] < z: # next_coord in moved_sharks
                moved_sharks[next_coord] = (s, next_d, z)
        
        sharks = moved_sharks
    
    print(result)

if __name__ == "__main__":
    main()
