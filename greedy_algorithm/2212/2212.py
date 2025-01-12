import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    k = int(input())
    sensors = sorted(list(set(map(int, input().split()))))
    print(sum(sorted([sensors[i + 1] - sensors[i] for i in range(len(sensors) - 1)])[:len(sensors) - k]))

if __name__ == "__main__":
    main()
