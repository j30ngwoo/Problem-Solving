#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

map<string, int> mbtiToIndex = {{"ISTJ", 0}, {"ISFJ", 1}, {"INFJ", 2}, {"INTJ", 3}, {"ISTP", 4}, {"ISFP", 5}, {"INFP", 6}, {"INTP", 7}, {"ESTP", 8}, {"ESFP", 9}, {"ENFP", 10}, {"ENTP", 11}, {"ESTJ", 12}, {"ESFJ", 13}, {"ENFJ", 14}, {"ENTJ", 15}};
map<int, string> indexToMbti = {{0, "ISTJ"}, {1, "ISFJ"}, {2, "INFJ"}, {3, "INTJ"}, {4, "ISTP"}, {5, "ISFP"}, {6, "INFP"}, {7, "INTP"}, {8, "ESTP"}, {9, "ESFP"}, {10, "ENFP"}, {11, "ENTP"}, {12, "ESTJ"}, {13, "ESFJ"}, {14, "ENFJ"}, {15, "ENTJ"}};

int cnt[16];
int t, n;

int calcDistance(int a, int b, int c) {
	int distance = 0;
	//cout << indexToMbti[a] << indexToMbti[b] << indexToMbti[c] << '\n';
	FOR(i, 4) {
		if (indexToMbti[a][i] != indexToMbti[b][i])
			++distance;
		if (indexToMbti[b][i] != indexToMbti[c][i])
			++distance;
		if (indexToMbti[c][i] != indexToMbti[a][i])
			++distance;
	}
	return (distance);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	FOR(x, t) {
		fill_n(cnt, 16, 0);
		cin >> n;
		FOR(y, n) {
			string currentInput;
			cin >> currentInput;
			if (cnt[mbtiToIndex[currentInput]] < 3) 
				cnt[mbtiToIndex[currentInput]]++;
		}
		int a = 0, b = 0, c = 0, result = INT32_MAX;
		FOR(a, 16) {
			if (cnt[a] >= 1)
				cnt[a]--;
			else
				continue;
			FOR(b, 16) {
				if (cnt[b] >= 1)
					cnt[b]--;
				else
					continue;
				FOR(c, 16) {
					if (cnt[c] >= 1)
						result = min(result, calcDistance(a, b, c));
				}
				cnt[b]++;
			}
			cnt[a]++;
		}
		cout << result << '\n';
	}
	return (0);
}