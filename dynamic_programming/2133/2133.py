import sys
input = lambda: sys.stdin.readline().strip()

def main():
    counts = [1, 0]
    for now in range(2, 31):
        count = 0
        for diff in range(4, now + 1, 2):
            count += counts[now - diff] * 2
        count += counts[now - 2] * 3
        counts.append(count)
    
    print(counts[int(input())])

if __name__ == "__main__":
    main()
