﻿import sys
from collections import deque
input = lambda: sys.stdin.readline().strip()

q = deque([i for i in range(1, int(input()) + 1)])

while len(q) > 1:
    q.popleft()
    q.append(q.popleft())

print(q.popleft())