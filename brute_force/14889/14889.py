import sys
input = lambda: sys.stdin.readline().strip()
from itertools import combinations 

def main():
    n = int(input())
    grid = []
    for _ in range(n):
        grid.append(list(map(int, input().split())))
    
    scores = dict()
    for team in combinations(range(n), n // 2):
        bit = 0
        for member in team:
            bit |= (1 << member)
        score = 0
        for member1 in team:
            for member2 in team:
                score += grid[member1][member2]
        scores[bit] = score
    
    result = float('inf')
    for team1 in scores.keys():
        team2 = ~team1 & ((1 << n) - 1)
        result = min(abs(scores[team1] - scores[team2]), result)
    
    print(result)


if __name__ == "__main__":
    main()
