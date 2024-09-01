import sys
input = lambda: sys.stdin.readline().strip()

s = input()
result = 0
for i in range(len(s) - 1):
	if s[i] != s[i + 1]:
		result += 10
	else:
		result += 5
print(result)