import sys
input = lambda: sys.stdin.readline().strip()

def main():
    dp = [[1, 0], [0, 1]]
    for i in range(2, 41):
        dp.append([dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1]])

    t = int(input())
    for _ in range(t):
        n = int(input())
        print(dp[n][0], dp[n][1])

if __name__ == "__main__":
    main()
