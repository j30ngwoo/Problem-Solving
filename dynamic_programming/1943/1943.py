import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    n = int(input())
    coins = []
    for _ in range(n):
        coins.append(list(map(int, input().split())))
    total = sum(coin[0] * coin[1] for coin in coins)
    
    if total % 2 == 1:
        print(0)
        return 
    
    target = total // 2 
    dp = [True] + [False] * target
    for coin, coin_count in coins:
        for i in range(target, -1, -1):
            if dp[i]:
                for count in range(1, coin_count + 1):
                    if i + coin * count > target:
                        break
                    dp[i + coin * count] = True
        if dp[target]:
            print(1)
            return
    
    print(0)

def main():
    for _ in range(3):
        solve()

if __name__ == "__main__":
    main()