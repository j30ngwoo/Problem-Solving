import sys
input = lambda: sys.stdin.readline().strip()

def main():
    h, w = map(int, input().split())
    blocks = list(map(int, input().split()))
    rains = blocks[:]

    max_index = 0
    for now_index in range(w):
        for rain_i in range(max_index + 1, now_index):
            rains[rain_i] = max(rains[rain_i], min(blocks[max_index], blocks[now_index]))
        if blocks[max_index] < blocks[now_index]:
            max_index = now_index
    
    print(sum(rains[i] - blocks[i] for i in range(w)))

if __name__ == "__main__":
    main()
