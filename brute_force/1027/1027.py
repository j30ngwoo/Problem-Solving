import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    heights = list(map(int, input().split()))
    counts = [0] * n

    def can_see(a, b):
        diff = heights[b] - heights[a]
        
        for i in range(1, b - a):
            if heights[a] + diff / (b - a) * i <= heights[a + i]:
                return False
        
        return True

    for a in range(n - 1):
        for b in range(a + 1, n):
            if can_see(a, b):
                counts[a] += 1
                counts[b] += 1

    #print(counts)
    print(max(counts))

if __name__ == "__main__":
    main()
