import sys
input = sys.stdin.readline.rstrip
print = sys.stdout.write

a = set()
b = set()

n, m = map(int, input().split()) 

for _ in range(n):
	a.add(input())
for _ in range(m):
	b.add(input())

result = list(a & b)
result.sort()

print(len(result), '\n')
for elem in result:
	print(elem, '\n')