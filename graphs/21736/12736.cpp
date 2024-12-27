#include <iostream>
#include <queue>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

struct Coord {
	int x, y;
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[600][600];
int n, m, result = 0;
queue<Coord> q;
Coord startCoord;

int main(void) {
	cin >> n >> m;
	FOR(y, n) {
		FOR(x, m) {
			cin >> map[y][x];
			if (map[y][x] == 'I')
				startCoord = {x, y};
		}
	}

	q.push(startCoord);
	map[startCoord.y][startCoord.x] = 'X';
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		FOR(i, 4) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY || map[nextY][nextX] == 'X')
				continue;
			if (map[nextY][nextX] == 'P')
				++result;
			q.push({nextX, nextY});
			map[nextY][nextX] = 'X';
		}
	}

	if (result == 0)
		cout << "TT";
	else
		cout << result;

	return (0);
}