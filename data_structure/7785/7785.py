import sys
input = sys.stdin.readline

n = int(input())
s = set()

for _ in range(n):
	name, log = input().split()
	if log == 'enter':
		s.add(name)
	else:
		s.remove(name)

l = list(s)
l.sort(reverse=True)
for e in l:
	print(e)