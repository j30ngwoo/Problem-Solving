import sys
input = lambda: sys.stdin.readline().strip()

t = int(input())

for _ in range(t):
	n, m = map(int, input().split())
	l = list(map(int, input().split()))
	q = [(i, e) for i, e in enumerate(l)]
	count = 0
	while q:
		first = q.pop(0)
		if not q or first[1] >= max(q, key=lambda x: x[1])[1]:
			count += 1
			if m == first[0]:
				print(count)
				break
		else:
			q.append(first)