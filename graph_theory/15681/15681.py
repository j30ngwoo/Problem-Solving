import sys
input = lambda: sys.stdin.readline().strip()

def main():
    sys.setrecursionlimit(10 ** 5 + 2)

    n, r, q = map(int, input().split())
    connect = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        s, e = map(int, input().split())
        connect[s].append(e)
        connect[e].append(s)

    def recursion(now_node, parent):
        count = 1
        for next_node in connect[now_node]:
            if next_node != parent:
                count += recursion(next_node, now_node)
        child_counts[now_node] = count
        return count

    child_counts = [0 for _ in range(n + 1)]
    recursion(r, -1)

    for _ in range(q):
        print(child_counts[int(input())])

if __name__ == "__main__":
    main()
