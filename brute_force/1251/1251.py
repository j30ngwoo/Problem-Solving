import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    word = input()
    result = []
    for i in range(1, len(word) - 1):
        for j in range(i + 1, len(word)):
            result.append(word[:i][::-1] + word[i:j][::-1] + word[j:][::-1])
    print(min(result))

if __name__ == "__main__":
    main()
