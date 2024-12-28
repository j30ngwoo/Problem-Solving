import sys
input = lambda: sys.stdin.readline().strip()

ATOZ = [chr(x) for x in range(ord('a'), ord('z') + 1)]

def solve():
    w = input()
    k = int(input())
    table = {x : [] for x in ATOZ}

    for pos, c in enumerate(w):
        table[c].append(pos)
    
    if all(len(l) < k for l in table.values()):
        print(-1)
        return

    min_result = float('inf')
    max_result = float('-inf')
    for l in table.values():
        if len(l) < k - 1:
            continue
        min_diff = float('inf')
        max_diff = float('-inf')
        for i in range(len(l) - (k - 1)):
            diff = l[i + (k - 1)] - l[i]
            min_diff = min(min_diff, diff)
            max_diff = max(max_diff, diff)
        min_result = min(min_result, min_diff + 1)
        max_result = max(max_result, max_diff + 1)

    print(min_result, max_result)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
