import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
s = set()

for _ in range(n):
	s.add(input())

s = list(s)
s.sort(key=lambda x: (len(x), x))

print('\n'.join(s))