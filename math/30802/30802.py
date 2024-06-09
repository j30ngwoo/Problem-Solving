n = int(input())
sizes = list(map(int, input().split()))
t, p = map(int, input().split())

t_count = 0
for size in sizes:
	if size % t == 0:
		t_count += size // t
	else:
		t_count += size // t + 1

print(t_count)
print(n // p, n % p)