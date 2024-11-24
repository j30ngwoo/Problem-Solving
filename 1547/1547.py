import sys
input = lambda: sys.stdin.readline().strip()

def main():
    m = int(input())
    ball = 1
    for _ in range(m):
        a, b = map(int, input().split())
        if a == ball:
            ball = b
        elif b == ball:
            ball = a
    
    print(ball)

if __name__ == "__main__":
    main()
