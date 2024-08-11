n, m = map(int, input().split())
l = list(range(n + 1))
for _ in range(m):
	a, b = map(int, input().split())
	l[a:b+1] = l[b:a-1:-1]
for e in l[1:]:
	print(e, end = ' ')