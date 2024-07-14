n = int(input())
arr = list(map(int, input().split()))
print(sum(arr) * 100 / (n * max(arr)))