import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    min_x = 10000
    max_x = -10000
    min_y = 10000
    max_y = -10000
    
    for _ in range(n):
        x, y = map(int, input().split())
        min_x = min(min_x, x)
        max_x = max(max_x, x)
        min_y = min(min_y, y)
        max_y = max(max_y, y)
    
    print((max_x - min_x) * (max_y - min_y))

if __name__ == "__main__":
    main()
