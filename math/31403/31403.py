import sys
input = lambda: sys.stdin.readline().strip()

a = int(input())
b = int(input())
c = int(input())

print(a + b - c)
print(int(str(a) + str(b)) - c)