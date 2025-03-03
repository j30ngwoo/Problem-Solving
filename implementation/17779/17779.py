import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    grid = [list(map(int, input().split())) for _ in range(n)]

    def get_min_diff(std_y, std_x, d1, d2):
        sums = []
        
        #1
        s = 0
        for y in range(std_y + d1):
            for x in range(min(std_x + 1, std_x - (y - std_y))):
                #print(y, x)
                s += grid[y][x]
        sums.append(s)

        #2
        s = 0
        for y in range(std_y + d2 + 1):
            for x in range(max(std_x + 1, std_x + (y - std_y) + 1), n):
                #print(y, x)
                s += grid[y][x]
        sums.append(s)

        #3
        s = 0
        for y in range(std_y + d1, n):
            for x in range(min(std_x - d1 + d2, (std_x - d1) + (y - (std_y + d1)))):
                s += grid[y][x]
        sums.append(s)

        #4
        s = 0
        for y in range(std_y + d2 + 1, n):
            for x in range(max(std_x - d1 + d2, (std_x + d2) - (y - (std_y + d2)) + 1), n):
                s += grid[y][x]
        sums.append(s)

        #5
        s = 0
        l = r = 0
        l_flip = r_filp = False
        for y in range(std_y, std_y + d1 + d2 + 1):
            s += sum(grid[y][(std_x - l):(std_x + r + 1)])
            if l >= d1:
                l_flip = True
            if r >= d2:
                r_filp = True
            if not l_flip:
                l += 1
            else:
                l -= 1
            if not r_filp:
                r += 1
            else:
                r -= 1
        sums.append(s)

        return max(sums) - min(sums)

    result = float('inf')
    for std_y in range(n - 2):
        for std_x in range(1, n - 1):
            for d1 in range(1, n - 1):
                for d2 in range(1, n - 1):
                    if std_y + d1 + d2 >= n or std_x < d1 or std_x + d2 >= n:
                        continue
                    result = min(result, get_min_diff(std_y, std_x, d1, d2))
    print(result)

if __name__ == "__main__":
    main()
