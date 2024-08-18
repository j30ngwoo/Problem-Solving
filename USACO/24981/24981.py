from bisect import bisect_left, bisect_right
import sys
input = sys.stdin.readline

n = int(input())
l = []
g = []
for _ in range(n):
	d, v = input().split()
	if d == 'L': l.append(int(v))
	else: g.append(int(v))

l.sort()
g.sort()
m = 0
for pos in l:
	m = max(m, bisect_right(g, pos) + (len(l) - bisect_left(l, pos)))
for pos in g:
	m = max(m, bisect_right(g, pos) + (len(l) - bisect_left(l, pos)))

print(n - m)