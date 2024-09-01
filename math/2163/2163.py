import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
print(n * m - 1)