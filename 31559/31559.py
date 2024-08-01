import sys
input = sys.stdin.readline

n, s = map(int, input().split())
jumps = [-1] * (n + 1)
target = [-1] * (n + 1)
for i in range(1, n + 1):
	q, v = map(int, input().split())
	if q == 0:
		jumps[i] = v
	else:
		target[i] = v

states = set()
pos = s
k = 1
direction = 1
result = 0
while 1 <= pos <= n and (pos, k, direction) not in states:
	states.add((pos, k, direction))
	if 0 <= target[pos] <= k:
		target[pos] = -1
		result += 1
	elif jumps[pos] >= 0:
		direction *= -1
		k += jumps[pos]
	pos += k * direction

print(result)