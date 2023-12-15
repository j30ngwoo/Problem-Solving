arr = []
individual_set = set()
two_set = set()

def count_victory(a, b, c):
	global individual_count, two_count
	if a == b == c:
		individual_set.add(a)
	elif a == b != c:
		two_set.add(str(sorted(a+c)))
	elif b == c != a:
		two_set.add(str(sorted(b+a)))
	elif c == a != b:
		two_set.add(str(sorted(c+b)))

for _ in range(3):
	arr.append(input())
for i in range(3):
	count_victory(arr[i][0], arr[i][1], arr[i][2])
	count_victory(arr[0][i], arr[1][i], arr[2][i])
count_victory(arr[0][0], arr[1][1], arr[2][2])
count_victory(arr[0][2], arr[1][1], arr[2][0])

print(len(individual_set))
print(len(two_set))
	
