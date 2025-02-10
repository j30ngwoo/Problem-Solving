import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = list(map(int, input().split()))

for i in range(n - 1, 0, -1):
    arr[i] -= arr[i - 1]
for i in range(n - 1, 0, -1):
    arr[i] -= arr[i - 1]

print(sum(map(abs, arr)))

# 개선해봤는데 더 오래 걸리네
# import sys
# input = lambda: sys.stdin.readline().strip()

# n = int(input())
# arr = [0] + list(map(int, input().split()))
# for i in range(n, 1, -1):
#     arr[i] = arr[i] - 2 * arr[i - 1] + arr[i - 2]

# print(sum(map(abs, arr)))