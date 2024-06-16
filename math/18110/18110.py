import sys
input = sys.stdin.readline

def myRound(x):
	return int(x + 0.5)

n = int(input())
if n == 0:
	print(0)
	exit(0)
arr = []
for _ in range(n):
	arr.append(int(input()))
arr.sort()
cut = myRound(n * 0.15)
arr = arr[cut:n - cut]
print(myRound(sum(arr) / (n - 2 * cut)))