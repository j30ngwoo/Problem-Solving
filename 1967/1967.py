import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
tree = [[] for _ in range(10001)]
for _ in range(n):
    p, c, w = map(int, input().split())
    tree[p].append((c, w))
    tree[c].append((p, w))

for 