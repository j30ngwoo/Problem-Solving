import sys
input = lambda: sys.stdin.readline().rstrip()

T = 0
P = 1

def main():
    n = int(input())
    arr = [tuple(map(int, input().split())) for _ in range(n)]
    max_profit = [0] * (n + 1)

    for day in range(n):
        time, profit = arr[day]
        for next_time in range(day + time, n + 1):
            max_profit[next_time] = max(max_profit[next_time], max_profit[day] + profit)

    print(max_profit[n]) 

if __name__ == "__main__":
    main()
