import sys

n, m = map(int, input().split())
word_list = [sys.stdin.readline().rstrip() for _ in range(n)]
word_dict = {}
for word in word_list:
    if word in word_dict:
        word_dict[word] += 1
    else:
        word_dict[word] = 1
sorted_words = sorted(list(set(word_list)), key=lambda x: (-word_dict[x], -len(x), x))
for word in sorted_words:
	if (len(word) >= m):
		print(word)