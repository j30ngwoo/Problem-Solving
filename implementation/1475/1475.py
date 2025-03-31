import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    l = [0] * 9
    sn = 0
    for e in map(int, input()):
        if e == 6 or e == 9:
            sn += 1
        else:
            l[e] += 1

    print(max(l + [sn // 2 if sn % 2 == 0 else sn // 2 + 1]))

if __name__ == "__main__":
    main()
