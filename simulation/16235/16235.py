import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

def main():
    DR = [-1, -1, -1, 0, 0, 1, 1, 1]
    DC = [-1, 0, 1, -1, 1, -1, 0, 1]

    n, m, k = map(int, input().split())
    energys = [[5 for _ in range(n)] for _ in range(n)]

    adds = []
    for _ in range(n):
        adds.append(list(map(int, input().split())))
    
    ages = [[deque() for _ in range(n)] for _ in range(n)]
    for _ in range(m):
        x, y, z = map(int, input().split())
        ages[x - 1][y - 1].append(z)

    def year():
        # spring, summer
        for r in range(n):
            for c in range(n):
                dead_energy = 0
                for _ in range(len(ages[r][c])):
                    age = ages[r][c].popleft()
                    if age <= energys[r][c]:
                        energys[r][c] = max(0, energys[r][c] - age)
                        ages[r][c].append(age + 1)
                    else:
                        dead_energy += age // 2
                energys[r][c] += dead_energy
        
        # fall, winter
        for r in range(n):
            for c in range(n):
                count_age5 = sum(age % 5 == 0 for age in ages[r][c])
                for d in range(8):
                    next_r = r + DR[d]
                    next_c = c + DC[d]
                    if 0 <= next_r < n and 0 <= next_c < n:
                        for _ in range(count_age5):
                            ages[next_r][next_c].appendleft(1)
                energys[r][c] += adds[r][c]

    for _ in range(k):
        year()
    
    result = 0
    for r in range(n):
        for c in range(n):
            result += len(ages[r][c])
    print(result)


if __name__ == "__main__":
    main()
