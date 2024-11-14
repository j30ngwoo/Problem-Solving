import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, L = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(list(map(int, input().split())))
    
    def is_line_available(line):
        is_there_lift = [False] * N
        for i in range(N - 1):
            if line[i] + 1 == line[i + 1]:
                if i - L + 1 < 0:
                    return False
                for sub_i in range(i - L + 1, i + 1):
                    if line[sub_i] != line[i] or is_there_lift[sub_i]:
                        return False
                    is_there_lift[sub_i] = True
            
            elif line[i] - 1 == line[i + 1]:
                if i + L >= N:
                    return False
                for sub_i in range(i + 1, i + L + 1):
                    if line[sub_i] != line[i] - 1:
                        return False
                    is_there_lift[sub_i] = True
            
            elif line[i] != line[i + 1]:
                return False
        
        return True

    count = 0
    for row in grid:
        if is_line_available(row):
            count += 1
    for x in range(N):
        col = [grid[y][x] for y in range(N)]
        if is_line_available(col):
            count += 1

    print(count)

if __name__ == "__main__":
    main()
