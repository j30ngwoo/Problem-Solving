import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, _ = map(int, input().split())

    max_ = 0
    max_count = 0
    for _ in range(N):
        s = input().split('0')
        lines = 0
        for e in s:
            if e:
                lines += 1

        if max_ < lines:
            max_count = 1
            max_ = lines
        elif max_ == lines:
            max_count += 1

    print(max_, max_count)

if __name__ == "__main__":
    main()
