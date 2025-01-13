import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    for _ in range(n):
        arr = list(map(int, input().split()))
        result = 1
        for i in range(min(arr) + 1, max(arr) + 1):
            result *= i
        for i in range(2, max(arr) - min(arr) + 1):
            result //= i
        print(result)

if __name__ == "__main__":
    main()
