#include <iostream>
#include <queue>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

struct coord {
	int x;
	int y;
};

int n, m, map[1000][1000];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<coord> q;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR(y, n) {
		FOR(x, m) {
			int input;
			cin >> input;
			if (input == 0)
				map[y][x] = 0;
			else if (input == 1)
				map[y][x] = -1;
			else {
				q.push({x, y});
				map[y][x] = 0;
			}
		}
	}
	
	while (!q.empty()) {
		int nowX = q.front().x;
		int nowY = q.front().y;
		q.pop();
		FOR(i, 4) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (map[nextY][nextX] == -1) {
				map[nextY][nextX] = map[nowY][nowX] + 1;
				q.push({nextX, nextY});
			}
		}
	}

	FOR(y, n) {
		FOR(x, m) {
			cout << map[y][x] << ' ';
		}
		cout << '\n';
	}

	return (0);
}