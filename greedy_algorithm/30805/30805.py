import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

result = []

while a and b:
    a_max = max(a)
    b_max = max(b)
    if a_max == b_max:
        result.append(a_max)
        a = a[a.index(a_max) + 1:]
        b = b[b.index(b_max) + 1:]
    elif a_max > b_max:
        a.pop(a.index(a_max))
    else: # a_max < b_max
        b.pop(b.index(b_max))

print(len(result))
if result:
    print(' '.join(map(str, result)))