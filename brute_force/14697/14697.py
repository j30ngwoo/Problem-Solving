import sys
input = lambda: sys.stdin.readline().strip()

def main():
    a, b, c, n = map(int, input().split())
    
    for i in range(n // a + 1):
        for j in range(n // b + 1):
            for k in range(n // c + 1):
                if a * i + b * j + c * k == n:
                    print(1)
                    return
    print(0)

if __name__ == "__main__":
    main()