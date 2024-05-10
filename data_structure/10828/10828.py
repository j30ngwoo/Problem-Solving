import sys
input = sys.stdin.readline

stack = []
n = int(input())

for _ in range(n):
	c = input().split()
	if c[0] == 'push':
		stack.append(int(c[1]))
	elif c[0] == 'pop':
		if len(stack) == 0:
			print(-1)
		else:
			print(stack[-1])
			del stack[-1]
	elif c[0] == 'size':
		print(len(stack))
	elif c[0] == 'empty':
		if len(stack) == 0:
			print(1)
		else:
			print(0)
	else:
		if len(stack) == 0:
			print(-1)
		else:
			print(stack[-1])