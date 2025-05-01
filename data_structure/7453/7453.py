
def main():
	n = int(input())
	arr1, arr2, arr3, arr4 = [], [], [], []
	for _ in range(n):
		a, b, c, d = map(int, input().split())
		arr1.append(a)
		arr2.append(b)
		arr3.append(c)
		arr4.append(d)
	
	table = dict()
	for a in arr1:
		for b in arr2:
			s = a + b
			if s in table:
				table[s] += 1
			else:
				table[s] = 1
	
	result = 0
	for c in arr3:
		for d in arr4:
			s = -c - d
			if s in table:
				result += table[s]
	
	print(result)

main()