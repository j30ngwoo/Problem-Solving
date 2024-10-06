import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
fruits = list(map(int, input().split()))
used_fruits = set()
prev_index = 0
result = 0
count = 0

for i in range(len(fruits)):
    if len(used_fruits) >= 2 and fruits[i] not in used_fruits:
        used_fruits.discard(fruits[prev_index])
        count = i - prev_index
    else:
        count += 1
    if fruits[i] != fruits[i - 1]:
            prev_index = i - 1
    used_fruits.add(fruits[i])
    result = max(result, count)

print(result)
