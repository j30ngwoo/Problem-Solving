import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, a, b = map(int, input().split())
    arr = [1] * n

    if n + 1 < a + b:
        print(-1)
        return

    if a == 1:
        arr[0] = b
        b -= 1

    for i in range(b):
        arr[n - i - 1] = i + 1

    if a > 1:
        if a >= b:
            for i in range(a):
                arr[n - b - i] = a - i
        else:
            for i in range(a - 1):
                arr[n - b - i - 1] = a - i - 1
    
    print(' '.join(map(str, arr)))

if __name__ == "__main__":
    main()
