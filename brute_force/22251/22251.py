import sys
input = lambda: sys.stdin.readline().strip()

def main():
    diffs = [
        [0, 4, 3, 3, 4, 3, 2, 3, 1, 2],
        [4, 0, 5, 3, 2, 5, 6, 1, 5, 4],
        [3, 5, 0, 2, 5, 4, 3, 4, 2, 3],
        [3, 3, 2, 0, 3, 2, 3, 2, 2, 1],
        [4, 2, 5, 3, 0, 3, 4, 3, 3, 2],
        [3, 5, 4, 2, 3, 0, 1, 4, 2, 1],
        [2, 6, 3, 3, 4, 1, 0, 5, 1, 2],
        [3, 1, 4, 2, 3, 4, 5, 0, 4, 3],
        [1, 5, 2, 2, 3, 2, 1, 4, 0, 1],
        [2, 4, 3, 1, 2, 1, 2, 3, 1, 0]
    ]

    n, k, p, x = map(int, input().split())
    x = list(map(int, list(str(x))))
    x = [0] * (k - len(x)) + x
    set_ = set()

    def recursion(changed_count, changed_x, depth):
        if depth == k:
            return
        a = x[depth]
        for b in range(10):
            if changed_count + diffs[a][b] <= p:
                temp = changed_x[:]
                temp[depth] = b
                int_temp = int(''.join(map(str, temp)))
                if 1 <= int_temp <= n:
                    set_.add(int_temp)
                recursion(changed_count + diffs[a][b], temp, depth + 1)

    recursion(0, x, 0)
    print(len(set_) - 1)

if __name__ == "__main__":
    main()
