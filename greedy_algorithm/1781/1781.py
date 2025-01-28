import sys
input = lambda: sys.stdin.readline().rstrip()
from heapq import heappush, heappop 


def main():
    n = int(input())
    noodles = [list(map(int, input().split())) for _ in range(n)]
    noodles.sort()

    pq = []
    for deadline, count in noodles:
        heappush(pq, count)
        if deadline < len(pq):
            heappop(pq)
    
    print(sum(pq))


if __name__ == "__main__":
    main()
