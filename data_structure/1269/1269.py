import sys
input = lambda: sys.stdin.readline().strip()

input()
a = set(map(int, input().split()))
b = set(map(int, input().split()))
print(len((a - b) | (b - a)))