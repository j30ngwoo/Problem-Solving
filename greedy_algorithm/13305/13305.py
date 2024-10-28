import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
roads = list(map(int, input().split()))
price = list(map(int, input().split()))

min_price = 1_000_000_000
result = 0
for i in range(n - 1):
    min_price = min(min_price, price[i])
    result += roads[i] * min_price
print(result)