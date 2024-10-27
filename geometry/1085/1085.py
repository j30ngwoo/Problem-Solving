import sys
input = lambda: sys.stdin.readline().strip()

x, y, w, h = map(int, input().split())
print(min(x, y, w - x, h - y))