#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct coord {
	int x;
	int y;
};

int t, m, n, k, cnt;
int map[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<coord> q;

void bfs(int x, int y) {
	q.push({x, y});
	while (!q.empty()) {
		int now_x = q.front().x;
		int now_y = q.front().y;
		q.pop();
		if (map[now_y][now_x] == 0)
			continue;
		map[now_y][now_x] = 0;
		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			if (0 <= next_x && next_x < m && 0 <=next_y && next_y < n && map[next_y][next_x] == 1)
				q.push({next_x, next_y});
		}
	}
}

int main(void) {
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> m >> n >> k;
		cnt = 0;
		fill_n(&map[0][0], 50 * 50, 0);
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (map[y][x] == 1) {
					bfs(x, y);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return (0);
}