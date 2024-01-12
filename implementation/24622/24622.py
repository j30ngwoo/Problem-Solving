from itertools import permutations

n = int(input())
blocks = []
for i in range(4):
	blocks.append(input())

for _ in range(n):
	word = input()
	p = list(permutations([0, 1, 2, 3], len(word)))
	isYes = False
	for indexs in p:
		count = 0
		for i in range(len(word)):
			if word[i] in blocks[indexs[i]]:
				count += 1
		if count == len(word):
			print('YES')
			isYes = True
			break
	if isYes == False:
		print('NO')
	