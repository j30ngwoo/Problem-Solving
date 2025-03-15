import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    p = list(input())
    for _ in range(n - 1):
        s = input()
        for i in range(len(s)):
            if p[i] != '?' and p[i] != s[i]:
                p[i] = '?'
    
    print(''.join(p))

if __name__ == "__main__":
    main()
