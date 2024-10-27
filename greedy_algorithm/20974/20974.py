import sys
input = lambda: sys.stdin.readline().strip()

ODD = 0
EVEN = 1

n = int(input())
cows = list(map(int, input().split()))

even = 0
odd = 0
for cow in cows:
    if cow % 2 == 0:
        even += 1
    else:
        odd += 1

result = 0
now_group_type = EVEN
while True:
    if now_group_type == EVEN:
        if even >= 1:
            even -= 1
        elif odd >= 2:
            odd -= 2
        else:
            break
        now_group_type = ODD
    else: # now_group_type == ODD
        if odd >= 1:
            odd -= 1
        else:
            break
        now_group_type = EVEN

    result += 1

if now_group_type == EVEN and odd % 2 == 1:
    result -= 1

print(result)

