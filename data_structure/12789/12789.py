import sys
input = lambda: sys.stdin.readline().strip()

from collections import deque

n = int(input())
line = deque(map(int, input().split()))
area = deque()

i = 1
while i <= n:
    if len(line) > 0 and i == line[0]:
        i += 1
        line.popleft()
    elif len(area) > 0 and i == area[-1]:
        i += 1
        area.pop()
    elif len(line) > 0:
        area.append(line.popleft())
    else:
        print("Sad")
        exit(0)

print("Nice")