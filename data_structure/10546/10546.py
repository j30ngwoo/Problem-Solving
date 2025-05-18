import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    s = set()
    for _ in range(2 * n - 1):
        name = input()
        if name in s:
            s.discard(name)
        else:
            s.add(name)
    print(s.pop())

if __name__ == "__main__":
    main()
