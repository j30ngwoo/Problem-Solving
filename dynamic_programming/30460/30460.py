import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = [0] + [*map(int, input().split())] + [0, 0]
    dp = [0 for _ in range(n + 3)]

    dp[1] = arr[1]
    dp[2] = dp[1] + arr[2]

    for i in range(3, n + 3):
        off = dp[i - 1] + arr[i]
        on = dp[i - 3] + sum(arr[(i - 2):(i + 1)]) * 2
        dp[i] = max(on, off)

    print(dp[n + 2])

if __name__ == "__main__":
    main()
