n = int(input())
arr = []

for i in range(n):
	arr.append(int(input()))
arr.sort(reverse=True)

max = 0
for index in range(n):
	weight = arr[index] * (index + 1)
	if (weight > max):
		max = weight
		
print(max)