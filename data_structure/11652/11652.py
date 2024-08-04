import sys
input = sys.stdin.readline

n = int(input())
d = dict()

for _ in range(n):
	x = int(input())
	if d.get(x) == None:
		d[x] = 1
	else:
		d[x] += 1

m_key = list(d.keys())[0]

for k, v in d.items():
	if d[m_key] < v:
		m_key = k
	elif d[m_key] == v:
		m_key = min(m_key, k)

print(m_key)