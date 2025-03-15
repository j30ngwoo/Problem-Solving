import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    s = list(map(int, input()))
    counts = [0, 0]
    counts[s[0]] += 1
    for i in range(1, len(s)):
        if s[i - 1] != s[i]:
            counts[s[i]] += 1
    print(min(counts))

if __name__ == "__main__":
    main()
