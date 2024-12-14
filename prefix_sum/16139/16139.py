import sys
input = lambda: sys.stdin.readline().strip()

def main():
    s = input()
    accum = [[0 for _ in range(26)]]
    for i in range(len(s)):
        accum.append(accum[i][:])
        code = ord(s[i]) - ord('a')
        accum[i + 1][code] = accum[i][code] + 1

    q = int(input())
    for _ in range(q):
        c, l, r = input().split()
        code, l, r = ord(c) - ord('a'), int(l), int(r)
        print(accum[r + 1][code] - accum[l][code])

if __name__ == "__main__":
    main()
