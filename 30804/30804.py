n = int(input())
arr = list(map(int, input().split()))
used_fruit = set()

left = 0
right = 0
result = 0
last_index = 0
while right < n:
	if len(used_fruit) <= 2:
		right += 1
		if arr[right] not in used_fruit:
			used_fruit.add(arr[right])
			last_index = right
	else:
		fruit_to_remove = arr[left]
		while arr[left] != fruit_to_remove:
			left += 1
		
	result = max(result, right - left)
print(result)