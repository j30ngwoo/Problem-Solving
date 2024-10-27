import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
sticks = []
for _ in range(n):
    sticks.append(int(input()))
sticks = sticks[::-1]

count = 0
max_height = 0
for stick in sticks:
    if stick > max_height:
        max_height = stick
        count += 1
print(count)