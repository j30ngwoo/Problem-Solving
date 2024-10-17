import sys
input = lambda: sys.stdin.readline().strip()
from queue import Queue

INF = 1000000
n, k = map(int, input().split())
arr = [[INF, 0] for _ in range(100001)]
q = Queue()
q.put((n, 0))

while not q.empty():
    now_pos, now_count = q.get()

    if not (0 <= now_pos <= 100000) or arr[k][0] < now_count:
        continue

    if arr[now_pos][0] < now_count:
        continue
    elif now_count <= arr[now_pos][0]:
        arr[now_pos][0] = now_count
        arr[now_pos][1] += 1

    q.put((now_pos + 1, now_count + 1))
    q.put((now_pos - 1, now_count + 1))
    q.put((now_pos * 2, now_count + 1))

print(arr[k][0], arr[k][1])