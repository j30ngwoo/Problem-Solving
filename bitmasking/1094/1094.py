x = int(input())
count = 0

while (x != 0):
	n = 64
	while (x < n):
		n /= 2
	x -= n
	count += 1

print(count)
