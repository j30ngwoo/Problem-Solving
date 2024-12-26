import sys
input = lambda: sys.stdin.readline().strip()

def main():
    t = int(input())
    base = [0, 0, 0]
    for digit in range(1, 9):
        base.append(base[-1] + int('5' * digit))

    for _ in range(t):
        n = int(input())
        digit = len(str(n))
        left = int('4' * digit)
        right = 10 ** (digit - 1) * 5

        if n <= left:
            print(base[digit])
        elif n < right:
            print(base[digit] + n - left)
        else:
            print(base[digit + 1])


if __name__ == "__main__":
    main()
