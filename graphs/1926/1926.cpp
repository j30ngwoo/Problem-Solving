#include <iostream>
#include <queue>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct coord {
	int x;
	int y;
};

int n, m, count, maximum;
int graph[500][500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<coord> q;

void bfs(int start_x, int start_y) {
	int area = 1;
	q.push({start_x, start_y});
	graph[start_y][start_x] = 0;
	while (!q.empty()) {
		int now_x = q.front().x;
		int now_y = q.front().y;
		q.pop();
		FOR(i, 4) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];
			if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n && graph[next_y][next_x] == 1) {
				graph[next_y][next_x] = 0;
				q.push({next_x, next_y});
				area++;
			}
		}
	}
	if (maximum < area)
		maximum = area;
}

int main(void) {
	cin >> n >> m;
	FOR(y, n) {
		FOR(x, m) {
			cin >> graph[y][x];
		}
	}

	int count = 0;
	FOR(y, n) {
		FOR(x, m) {
			if (graph[y][x] == 1) {
				bfs(x, y);
				count++;
			}
		}
	}
	cout << count << '\n' << maximum;
}