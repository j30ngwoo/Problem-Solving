import sys
input = lambda: sys.stdin.readline().strip()

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    cows = input()
    grass = ['.'] * n
    count = 0
    next_G = 0
    next_H = 0
    for i in range(n):
        if cows[i] == 'G' and next_G <= i:
            for now_G in range(min(i + k, n - 1), -1, -1):
                if grass[now_G] == '.':
                    grass[now_G] = 'G'
                    break
            next_G = i + (2 * k + 1)
            count += 1
        elif cows[i] == 'H' and next_H <= i:
            for now_H in range(min(i + k, n - 1), -1, -1):
                if grass[now_H] == '.':
                    grass[now_H] = 'H'
                    break
            next_H = i + (2 * k + 1)
            count += 1
    print(count)
    print(''.join(grass))