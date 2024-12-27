#include <iostream>
#include <queue>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
using namespace std;

struct s {
	int position;
	int count;
};

struct compare {
	bool operator()(const s& a, const s& b) {
		return a.count > b.count;
	}
};

int n, m, x, y;
int minimum[101], ladder[101], snake[101];
bool isVisited[101];
priority_queue<s, vector<s>, compare> q;

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
		int position = q.top().position;
		int count = q.top().count;
		q.pop();
		if (isVisited[position] || position > 100)
			continue ;
		//cout << "pos: " << position << '\n';
		isVisited[position] = true;
		if (position == 100) {
			cout << count;
			return (0);
		}
		if (ladder[position])
			q.push({ladder[position], count});
		else if (snake[position])
			q.push({snake[position], count});
		else 
			FOR1 (i, 6)
				q.push({position + i, count + 1});
	}
	return (0);
}