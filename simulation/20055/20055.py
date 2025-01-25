import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    robots = []

    result = 1
    while True:
        arr.insert(0, arr.pop())
        robots = [(pos + 1) % (2 * n) for pos in robots]
        if n - 1 in robots:
            robots.remove(n - 1)

        for i in range(len(robots)):
            next_pos = (robots[i] + 1) % (2 * n)
            if next_pos not in robots and arr[next_pos] >= 1:
                robots[i] = next_pos
                arr[robots[i]] -= 1
        if n - 1 in robots:
            robots.remove(n - 1)

        if arr[0] >= 1:
            robots.append(0)
            arr[0] -= 1
        
        if arr.count(0) >= k:
            break
    
        result += 1

    print(result)

if __name__ == "__main__":
    main()
