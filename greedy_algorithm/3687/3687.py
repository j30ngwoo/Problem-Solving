import sys
input = lambda: sys.stdin.readline().strip()

def main():
    base = [0, 0, 1, 7, 4, 2, 6, 8, 10]
    results = base + [float('inf')] * 93
    base[6] = 0
    for i in range(9, 101):
        for b in range(2, 8):
            results[i] = min(results[i], results[i - b] * 10 + base[b])

    t = int(input())
    for _ in range(t):
        n = int(input())
        print(results[n], end=' ')

        if n % 2 == 0:
            print('1' * (n // 2))
        else:
            print('7' + '1' * (n // 2 - 1))

if __name__ == "__main__":
    main()
