import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    words = []
    for _ in range(n):
        words.append(input())

    max_len = 0
    min_index = float('inf')
    dict_ = dict()
    result = None
    for index, word in enumerate(words):
        for now_len in range(1, len(word) + 1):
            sub_word = word[:now_len]
            get_index = dict_.get(sub_word)
            if get_index == None:
                dict_[sub_word] = index
            elif max_len == now_len and get_index < min_index:
                result = [words[get_index], word]
                min_index = get_index
            elif max_len < now_len:
                result = [words[get_index], word]
                max_len = now_len
                min_index = get_index

    if result:
        print(result[0])
        print(result[1])
    else:
        print(words[0])
        print(words[1])


if __name__ == "__main__":
    main()
