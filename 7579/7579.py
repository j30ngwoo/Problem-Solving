import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, m = map(int, input().split())
    mems = list(map(int, input().split()))
    costs = list(map(int, input().split()))
    
    cost_mem = {0:0}
    for i in range(n):
        #print(cost_mem)
        for cost, mem in list(cost_mem.items()):
            next_mem, next_cost = mem + mems[i], cost + costs[i]
            if next_cost not in cost_mem or cost_mem[next_cost] < next_mem:
                cost_mem[next_cost] = next_mem
    
    result = float('inf')
    for cost, mem in cost_mem.items():
        if mem >= m:
            result = min(result, cost)
    print(result)

if __name__ == "__main__":
    main()
