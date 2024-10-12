import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = [int(input()) for _ in range(n)]
arr.sort()

print(int(round(sum(arr) / len(arr), 0)))

print(arr[len(arr) // 2])

d = dict()
for e in arr:
    if d.get(e):
        d[e] += 1
    else:
        d[e] = 1
l = list(d.items())
l.sort(reverse=True, key=lambda x: x[1])
if len(l) >= 2 and l[0][1] == l[1][1]:
    print(l[1][0])
else:
    print(l[0][0])

print(arr[-1] - arr[0])