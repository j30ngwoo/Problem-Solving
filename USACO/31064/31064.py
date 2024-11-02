from math import ceil
import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
bits = list(map(int, input()))

mass = []
i = 0
while i < n:
    if bits[i] == 1:
        count = 0
        while i < n and bits[i] == 1:
            count += 1
            i += 1
        mass.append(count)
    else:
        i += 1

if sum(mass) == 0:
    print(0)
    exit(0)

temp = mass[:]
if bits[0] == 1:
    temp[0] = temp[0] * 2 - 1
if bits[-1] == 1:
    temp[-1] = temp[-1] * 2 - 1
day = ((min(temp) - 1) // 2)

for i in range(len(mass)):
    mass[i] = ceil(mass[i] / (day * 2 + 1))

print(sum(mass))
