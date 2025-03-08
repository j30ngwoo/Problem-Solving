import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, K = map(int, input().split())
    s = input().split()
    
    count = len(s[0])
    print(s[0], end='')

    for w in s[1:]:
        if K < count + len(w):
            print()
            count = 0
        else:
            print(end=' ')
        
        print(w, end='')
        count += len(w)

if __name__ == "__main__":
    main()
