import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    p = int(input())
    for pi in range(p):
        l = list(map(int, input().split()))[1:]
        line = [l[0]]
        count = 0
        for e in l[1:]:
            pos = len(line)
            for i in range(len(line)):
                if e < line[i]:
                    pos = i
                    break
            count += len(line) - pos
            line.insert(pos, e)
        print(pi + 1, count)


if __name__ == "__main__":
    main()
