import sys
input = lambda: sys.stdin.readline().strip()

def main():
    s = input()
    p = input()

    sub_strs = set()
    for a in range(len(s)):
        for b in range(a + 1, len(s) + 1):
            sub_strs.add(s[a:b])
    
    start = 0
    count = 0
    while start < len(p):
        count += 1
        stop = start + 1
        while stop < len(p) and p[start:stop + 1] in sub_strs:
            stop += 1
        start = stop

    print(count)


if __name__ == "__main__":
    main()
