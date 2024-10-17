import sys
input = lambda: sys.stdin.readline().strip()
from queue import Queue

INF = 1000000
n, k = map(int, input().split())
arr = [-1] * 100001 
count = 0
q = Queue()

arr[n] = 0
q.put(n)

while not q.empty():
    now_pos = q.get()

    if now_pos == k:
        count += 1
        continue

    if now_pos < 30:
        print(str(arr[:30]).replace("-1", "_"))
    
    for next_pos in (now_pos + 1, now_pos -1, now_pos * 2):
        if 0 <= next_pos <= 100000 and (arr[next_pos] == -1 or arr[next_pos] > arr[now_pos]):
            arr[next_pos] = arr[now_pos] + 1
            q.put(next_pos)

print(arr[k])
print(count)