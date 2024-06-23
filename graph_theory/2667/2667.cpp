#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct coord {	
	int x;
	int y;	
};

int n, count;
string map[25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<coord> q;
vector<int> result;

int bfs(int x, int y) {
	int count = 0;
	q.push({x, y});
	while (!q.empty()) {
		int now_x = q.front().x;
		int now_y = q.front().y;
		q.pop();
		if (map[now_y][now_x] == '0')
			continue;
		map[now_y][now_x] = '0';
		count++;
		for (int d = 0; d < 4; d++) {
			int next_x = now_x + dx[d];
			int next_y = now_y + dy[d];
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n && map[next_y][next_x] == '1') {
				q.push({next_x, next_y});
			}
		}
	}
	return (count);
}

int main(void) {
	cin >> n;
	for (int y = 0; y < n; y++)
		cin >> map[y];

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '1')
				result.push_back(bfs(x, y));
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int e : result) {
		cout << e << '\n';
	}
}