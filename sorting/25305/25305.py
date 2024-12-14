import sys
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
scores = list(map(int, input().split()))
scores.sort(reverse=True)
print(scores[k - 1])