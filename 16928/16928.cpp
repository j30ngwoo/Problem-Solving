#include <iostream>
#include <queue>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

struct s {
	int position;
	int count;
};

int n, m, x, y;
int minimum[101], ladder[101], snake[101];
queue<s> q;

int main(void) {
	cin >> n >> m;
	FOR (i, n) {
		cin >> x >> y;
		ladder[x] = y;
	}
	FOR (i, m) {
		cin >> x >> y;
		snake[x] = y;
	}

	q.push({1, 0});
	while (!q.empty()) {
		int position = q.front().position;
		int count = q.front().count;
		q.pop();
		if (position == 100) {
			cout << count;
			return (0);
		}
		if (ladder[position])
			q.push({count, ladder[position]});
		else if (snake[position])
			q.push({count, snake[position]});
		for
	}

	return (0);
}