import sys
input = lambda: sys.stdin.readline().strip()

START = 0
STOP = 1

def round_up(a, b):
    if a % b == 0:
        return a // b
    else:
        return a // b + 1

def main():
    N, L = map(int, input().split())
    planks = []
    for _ in range(N):
        planks.append(tuple(map(int, input().split())))
    planks.sort()
    
    plank_stop = 0
    result = 0
    for start, stop in planks:
        if stop <= plank_stop:
            continue
        
        start = max(start, plank_stop)
        count = round_up(stop - start, L)
        result += count
        plank_stop = start + count * L

    print(result)

if __name__ == "__main__":
    main()
