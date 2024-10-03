import sys
input = lambda: sys.stdin.readline().strip()

a, b, x, y = map(int, input().split())
d1 = abs(a - b)
d2 = abs(a - x) + abs(b - y)
d3 = abs(a - y) + abs(b - x)
print(min(d1, d2, d3))
