import sys
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(1000000)

def main():
    g, p = int(input()), int(input())
    parents = [i for i in range(g + 1)]
    result = 0

    def find(c):
        if parents[c] == c:
            parents[c] = c - 1
            return parents[c]
        parents[c] = find(parents[c])
        return parents[c]

    for _ in range(p):
        gate = int(input())
        find(gate)
        if parents[gate] == -1:
            break
        result += 1

    print(result)

if __name__ == "__main__":
    main()
