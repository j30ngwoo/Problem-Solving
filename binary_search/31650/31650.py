from bisect import bisect_right
import sys
input = sys.stdin.readline

n, q = map(int, input().split())
diff = sorted([c - t for c, t in zip(list(map(int, input().split())), list(map(int, input().split())))])
for _ in range(q):
	v, s = map(int, input().split())
	print("YES") if v <= n - bisect_right(diff, s) else print("NO")\
