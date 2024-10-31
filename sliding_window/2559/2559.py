import sys
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
arr = list(map(int, input().split()))

s = sum(arr[0:k])
result = s
for i in range(n - k):
    s = s - arr[i] + arr[i + k]
    result = max(result, s)

print(result)