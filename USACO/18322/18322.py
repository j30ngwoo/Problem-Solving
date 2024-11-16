import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, K = map(int, input().split())
    s = input().split()
    
    count = 0
    for i in range(N):
        if K < count + len(s[i]):
            print()
            count = 0
        elif 0 < i:
            print(end=' ')
        
        print(s[i], end='')
        count += len(s[i])

if __name__ == "__main__":
    main()
