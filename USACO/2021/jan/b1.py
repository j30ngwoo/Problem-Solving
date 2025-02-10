import sys
input = lambda: sys.stdin.readline().strip()

alpha = input()
s = input()
count = 0
d = dict()

for i in range(26):
	d[alpha[i]] = i

last_index = d[s[0]]
for c in s:
	if d[c] <= last_index:
		count += 1
	last_index = d[c]

print(count)