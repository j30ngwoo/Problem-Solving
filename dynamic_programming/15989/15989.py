import sys
input = lambda: sys.stdin.readline().strip()

def main():
    dp = [[0, 0, 0], [1, 0, 0], [1, 1, 0], [1, 1, 1]] + [[0, 0, 0] for _ in range(10001)]

    for i in range(4, 10001):
        dp[i][0] = dp[i - 1][0]
        dp[i][1] = dp[i - 2][0] + dp[i - 2][1]
        dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2]
    
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(sum(dp[n]))

if __name__ == "__main__":
    main()
