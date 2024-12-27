import sys
input = lambda: sys.stdin.readline().strip()
sys.setrecursionlimit(10**9)

n = int(input())
tree = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    p, c, w = map(int, input().split())
    tree[p].append([c, w])
    tree[c].append([p, w])

max_node = 0
max_len = 0

def find_max_len(prev_node, now_node, l):
    global max_node, max_len

    if l > max_len:
        max_len = l
        max_node = now_node

    for next_node, w in tree[now_node]:
        if next_node == prev_node:
            continue
        find_max_len(now_node, next_node, l + w)

find_max_len(-1, 1, 0)
find_max_len(-1, max_node, 0)
print(max_len)