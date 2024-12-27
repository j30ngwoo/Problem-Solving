import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = [0]
    for _ in range(n):
        arr.append(int(input()))
    
    result_list = []
    for start in range(1, n + 1):
        if start in result_list:
            continue
        temp_list = [start]
        while True:
            next = arr[temp_list[-1]]
            if next in temp_list:
                if next == start:
                    result_list += temp_list
                break
            temp_list.append(next)
    
    print(len(result_list))
    print('\n'.join(map(str, sorted(list(result_list)))))

if __name__ == "__main__":
    main()
