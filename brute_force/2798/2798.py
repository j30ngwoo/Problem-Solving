import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))

    result = 0
    for a in range(n - 2):
        for b in range(a + 1, n - 1):
            for c in range(b + 1, n):
                sum_ = arr[a] + arr[b] + arr[c]
                if sum_ <= m:
                    result = max(result, sum_)

    print(result)

if __name__ == "__main__":
    main()
