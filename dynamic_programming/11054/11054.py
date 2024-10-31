import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = list(map(int, input().split()))

ascending = [1] * n
for now in range(n):
    for prev in range(now):
        if arr[prev] < arr[now]:
            ascending[now] = max(ascending[now], ascending[prev] + 1)

descending = [1] * n
for now in range(n - 1, -1, -1):
    for next in range(now + 1, n):
        if arr[now] > arr[next]:
            descending[now] = max(descending[now], descending[next] + 1)

result = [a + d for a, d in zip(ascending, descending)]
print(max(result) - 1)