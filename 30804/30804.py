n = int(input())
arr = list(map(int, input().split()))
used_fruit = []

left = 0
right = 0
result = 0
last_index = 0
while right < n:
	if len(used_fruit) >= 2 and arr[right] not in used_fruit:
		if used_fruit[0] != arr[last_index]:
			used_fruit.pop(0)
		elif used_fruit[1] != arr[last_index]:
			used_fruit.pop(1)
		left = last_index
	if right >= 1 and arr[right] != arr[right - 1]:
		last_index = right
	result = max(result, right - left)
	print(left, right)
	right += 1
print(result)