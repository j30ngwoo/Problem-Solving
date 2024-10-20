import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
dirs = input()
dirs = dirs[-1] + dirs + dirs[0]
buckets = [None] + list(map(int, input().split())) + [None]


def leak_start(now_pos):
    remain_milk = m
    while remain_milk > 0:
        if dirs[now_pos] == 'R' and dirs[now_pos + 1] == 'L':
            break
        if dirs[now_pos - 1] == 'R' and dirs[now_pos] == 'L':
            break
        
        sub = min(remain_milk, buckets[now_pos])
        remain_milk -= sub
        buckets[now_pos] -= sub
        
        if dirs[now_pos] == 'R':
            now_pos += 1
        else:
            now_pos -= 1
        
        if now_pos == 0:
            now_pos = n
        elif now_pos == n + 1:
            now_pos = 1


for i in range(1, n + 1):
    if dirs[i - 1] == 'L' and dirs[i + 1] == 'R':
        leak_start(i)

print(sum(buckets[1:(n + 1)]))
