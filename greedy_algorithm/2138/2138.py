import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    a = list(map(int, list(input())))
    b = list(map(int, list(input())))
    save_a = a[:]

    def push(i):
        if i - 1 >= 0:
            a[i - 1] = int(not a[i - 1])
        a[i] = int(not a[i])
        if i + 1 < n:
            a[i + 1] = int(not a[i + 1])

    count = 0
    for i in range(1, n):
        if a[i - 1] != b[i - 1]:
            push(i)
            count += 1    
    if a == b:
        print(count)
        return

    a = save_a[:]
    push(0)
    count = 1
    for i in range(1, n):
        if a[i - 1] != b[i - 1]:
            push(i)
            count += 1
    if a == b:
        print(count)
        return

    print(-1)

if __name__ == "__main__":
    main()
