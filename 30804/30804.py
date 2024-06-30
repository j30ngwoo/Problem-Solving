n = int(input())
arr = list(map(int, input().split()))
accum = []
is_used = set()
for e in arr:
	if e in is_used:
		accum += accum[-1]
	else:
		is_used.add(e)
		accum += accum[-1] + 1

left = 0
right = 0
while right < n:
	if accum[left]