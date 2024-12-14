import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))
	
	result = 0
	for l in range(n):
		remain_k = k
		now_len = 1
		r = l + 1
		while r < n and remain_k >= 0:
			if arr[l] == arr[r]:
				now_len += 1
			else:
				remain_k -= 1
			r += 1
		result = max(now_len, result)
	
	print(result)


if __name__ == '__main__':
	main()