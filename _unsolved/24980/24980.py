n = int(input())
cows = input()
arr = []
for i in range(0, len(cows), 2):
	substr = cows[i:i + 2]
	if substr == 'GH':
		arr.append(0)
	elif substr == 'HG':
		arr.append(1)
#print(arr)
count = 0
flagGH = False
for e in arr:
	if e == 0 and flagGH == False:
		count += 1
		flagGH = True
	if e == 1:
		flagGH = False
print(count)
