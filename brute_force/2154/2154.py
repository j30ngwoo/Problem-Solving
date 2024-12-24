import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    s = '0'
    for i in range(1, n + 1):
        s += str(i)
    i = 1
    str_n = str(n)
    while s[i:(i + len(str_n))] != str_n:
        i += 1
    print(i)

if __name__ == "__main__":
    main()
