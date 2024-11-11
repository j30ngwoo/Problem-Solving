import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    cows = input()
    e = list(map(lambda x: x - 1, map(int, input().split())))

    first_G = None
    last_G = None
    first_H = None
    last_H = None
    for i in range(n):
        if cows[i] == 'G':
            last_G = i
            if first_G == None:
                first_G = i
        else:
            last_H = i
            if first_H == None:
                first_H = i

    if last_G <= e[first_G]:
        is_first_G_leader = True
    else:
        is_first_G_leader = False
    if last_H <= e[first_H]:
        is_first_H_leader = True
    else:
        is_first_H_leader = False

    result = 0
    for i in range(n):
        if cows[i] == 'G' and is_first_H_leader and i <= first_H <= e[i]:
            result += 1
        elif cows[i] == 'H' and is_first_G_leader and i <= first_G <= e[i]:
            result += 1
    
    if is_first_G_leader and is_first_H_leader:
        if not first_G <= first_H <= e[first_G] or first_H <= first_H <= e[first_H]:
            result += 1
    
    print(result)

if __name__ == "__main__":
    main()
