import sys
input = lambda: sys.stdin.readline().strip()

def main():
    print(int(str(sum(map(lambda x: int(x[::-1]), input().split())))[::-1]))

if __name__ == "__main__":
    main()
