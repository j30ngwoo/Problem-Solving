import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
set_ = set()
result = 0

for _ in range(n):
    s = input()
    if s == "ENTER":
        result += len(set_)
        set_.clear()
    else:
        set_.add(s)

result += len(set_)
print(result)