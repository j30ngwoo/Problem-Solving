import sys
input = sys.stdin.readline

def fibo(i):
	if d.get(i) != None:
		return d[i]
	if i % 2 == 0:
		d[i] = (fibo(i + 1) - fibo(i - 1)) % 1000000007
		return d[i]
	else:
		d[i] = (fibo(i // 2) ** 2 + fibo(i // 2 + 1) ** 2) % 1000000007
		return d[i]

d = {0:0, 1:1, 2:1}
print(fibo(int(input())))
