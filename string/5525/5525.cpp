#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;

	int i = 0, count = 0, result = 0;
	while (i < m - 2) {
		if (s.substr(i, 3) == "IOI") {
			++count;
			i += 2;
		} else {
			count = 0;
			i += 1;
		}
		if (count == n) {
			--count;
			++result;
		}
	}
	cout << result;
}


/*
int countIOI[1000001];
int n, m, result;
string s;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;
	for (int i = 2; i < m; i++)
		if (s.substr(i - 2, 3) == "IOI")
			countIOI[i] = countIOI[i - 2] + 1;
	for (int i = 2; i < m; i++)
		if (n <= countIOI[i])
			result++;
	cout << result;

	return (0);
}
*/