import sys
input = sys.stdin.readline

def checker(s):
	_set = set()
	for i in range(len(s)):
		if i > 0 and s[i - 1] == s[i] or not s[i] in _set:
			_set.add(s[i])
			continue
		return False
	return True

count = 0
for _ in range(int(input())):
	if checker(input()):
		count += 1
print(count)

