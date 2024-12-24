import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    s = ''
    for i in range(1, n + 1):
        s += str(i)
    i = 0
    while s[i:(i + len(str(n)))] != str(n):
        i += 1
    print(i + 1)

if __name__ == "__main__":
    main()
