import sys
input = lambda: sys.stdin.readline().strip()

def recursion(index, layer):
    if layer == 0:
        print(" ".join(map(str, arr)))
        return

    for next_index in range(index, len(l)):
        arr.append(l[next_index])
        recursion(next_index, layer - 1)
        arr.pop()


n, m = map(int, input().split())
l = sorted(list(set(map(int, input().split()))))

arr = []
recursion(0, m)
