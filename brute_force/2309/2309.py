arr = []
for i in range(9):
	arr.append(int(input()))
arr.sort()
s = sum(arr)
for a in range(8):
	for b in range(a + 1, 9):
		if s - arr[a] - arr[b] == 100:
			for i in range(9):
				if i != a and i != b:
					print(arr[i])
			exit(0)