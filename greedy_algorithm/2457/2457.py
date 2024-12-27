import sys
input = lambda: sys.stdin.readline().strip()

L = 0
R = 1
DAYS = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
DAY_3_1 = 60
DAY_12_1 = 335

def main():
    n = int(input())
    flowers = []
    for _ in range(n):
        m1, d1, m2, d2 = map(int, input().split())
        start = d1
        for i in range(1, m1):
            start += DAYS[i]
        stop = d2
        for i in range(1, m2):
            stop += DAYS[i]
        flowers.append([start, stop])

    flowers.sort(key=lambda x: x[L])
    result = 0
    start = DAY_3_1
    stop = DAY_3_1
    i = 0
    while i < n and stop < DAY_12_1:
        result += 1
        if start < flowers[i][L]:
            i += 1
        while i < n and flowers[i][L] <= start:
            if stop < flowers[i][R]:
                stop = flowers[i][R]
            i += 1
        start = stop
    
    if DAY_12_1 <= stop:
        print(result)
    else:
        print(0)

if __name__ == "__main__":
    main()
