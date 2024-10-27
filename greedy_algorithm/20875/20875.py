import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
cows = list(map(int, input().split()))
stalls = list(map(int, input().split()))
cows.sort(reverse=True)

def count_possible_stalls(h):
    count = 0
    for stall in stalls:
        if h <= stall:
            count += 1
    return count

result = 1
for i in range(n):
    result *= count_possible_stalls(cows[i]) - i
print(result)