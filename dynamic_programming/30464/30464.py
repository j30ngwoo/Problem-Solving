import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = [*map(int, input().split())]
    dp = [0] * n

    for i in range(n - 1, -1, -1):
        next_i = i + arr[i]
        if next_i == n - 1:
            dp[i] = 1
        elif next_i < n and dp[next_i] != 0:
            dp[i] = dp[next_i] + 1
    
    for i in range(n - 1):
        next_i = i - arr[i]
        if 0 <= next_i and dp[next_i] != 0:
            dp[i] = max(dp[i], dp[next_i] + 1)
    
    for i in range(n - 1, -1, -1):
        next_i = i + arr[i]
        if next_i < n - 1 and dp[next_i] != 0:
            dp[i] = max(dp[i], dp[next_i] + 1)
    
    if dp[0] == 0:
        print(-1)
    else:
        print(dp[0])

if __name__ == "__main__":
    main()

