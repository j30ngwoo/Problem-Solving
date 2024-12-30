import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, m, h = map(int, input().split())
    lines = [[False for _ in range(h + 1)] for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        lines[b][a] = True
    
    def is_available():
        for start_x in range(1, n + 1):
            now_x = start_x
            for y in range(1, h + 1):
                if lines[now_x - 1][y]:
                    now_x -= 1
                elif lines[now_x][y]:
                    now_x += 1
            if now_x != start_x:
                return False
        return True
    
    if is_available():
        print(0)
        return

    result = 4
    def recursion(x, y, depth):
        nonlocal result

        if x >= n:
            x = 1
            y += 1
        while y <= h:
            if lines[x - 1][y] == lines[x][y] == lines[x + 1][y] == False:
                lines[x][y] = True
                if is_available():
                    result = min(result, depth)
                elif depth < result - 1:
                    recursion(x + 2, y, depth + 1)
                lines[x][y] = False
            
            x += 1
            if x >= n:
                x = 1
                y += 1
            
    recursion(1, 1, 1)
    if 1 <= result <= 3:
        print(result)
    else:
        print(-1)

if __name__ == "__main__":
    main()
