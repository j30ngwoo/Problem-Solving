import sys
input = lambda: sys.stdin.readline().strip()

def main():
    s = input()
    set_ = set()
    
    for l in range(len(s)):
        for r in range(l + 1, len(s) + 1):
            set_.add(s[l:r])

    print(len(set_))

if __name__ == "__main__":
    main()
