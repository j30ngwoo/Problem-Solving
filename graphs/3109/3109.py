import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    r, c = map(int, input().split())
    grid = [list(input()) for _ in range(r)]

    def dfs(y, x):
        nonlocal is_found, result
        
        if is_found:
            return
        
        grid[y][x] = 'x'

        if x == c - 1:
            result += 1
            is_found = True
            return
        
        for next_y in range(y - 1, y + 2):
            if 0 <= next_y < r and grid[next_y][x + 1] == '.':
                dfs(next_y, x + 1)       

    result = 0
    for y in range(r):
        if grid[y][0] == 'x':
            continue
        is_found = False
        dfs(y, 0)
    
    print(result)

if __name__ == "__main__":
    main()
