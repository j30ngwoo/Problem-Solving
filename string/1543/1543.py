import sys
input = lambda: sys.stdin.readline().strip()

def main():
    s = input()
    word = input()
    result = 0
    i = 0
    while i < len(s) - len(word) + 1:
        if s[(i):(i + len(word))] == word:
            result += 1
            i += len(word)
        else:
            i += 1
    
    print(result)

if __name__ == "__main__":
    main()
