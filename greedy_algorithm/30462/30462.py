import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    b = [*map(int, input().split())]

    if sorted(b) != b:
        print('No')
        exit(0)

    if b[n - 1] != n + 1:
        print('No')
        exit(0)

    for i in range(n):
        if b[i] > i + 2:
            print('No')
            exit(0)
    
    is_selected = [False] * (n + 2)
    a = [0] * n
    for i in range(1, n):
        if b[i] != b[i - 1]:
            a[i] = b[i - 1]
            is_selected[b[i - 1]] = True

    now_num = 1
    for i in range(n):
        if a[i] != 0:
            continue

        while is_selected[now_num]:
            now_num += 1

        a[i] = now_num
        is_selected[now_num] = True
    
    print('Yes')
    print(' '.join(map(str, a)))


if __name__ == "__main__":
    main()
