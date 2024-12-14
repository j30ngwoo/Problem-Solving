s = input()
t = input()

def recursion(now_s):
	if len(now_s) > len(t):
		return
	
	if now_s not in t and now_s[::-1] not in t:
		return
	
	if now_s == t:
		print(1)
		exit(0)
	
	recursion(now_s + 'A')
	recursion((now_s + 'B')[::-1])

recursion(s)
print(0)