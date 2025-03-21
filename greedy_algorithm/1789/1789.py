import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    s = int(input())
    my_s = 0
    i = 0
    while my_s < s:
        i += 1
        my_s += i

    if s < my_s:
        print(i - 1)
    else:
        print(i)

if __name__ == "__main__":
    main()
