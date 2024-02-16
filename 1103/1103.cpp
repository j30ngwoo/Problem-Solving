#include <vector>
#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int n, m, result = 0;
int map[50][50], maximum[50][50];
bool isVisited[50][50];

void recursion(int x, int y, int count) {
	if (isVisited[y][x] == true) {
		cout << -1;
		exit(0);
	}
	if (result < count)
		result = count;
	maximum[y][x] = count;
	isVisited[y][x] = true;
	FOR(d, 4) {
		int nextX = x + dx[d] * map[y][x];
		int nextY = y + dy[d] * map[y][x];
		if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY 
			|| map[nextY][nextX] == 0 || count + 1 <= maximum[nextY][nextX])
			continue;
		//cout << nextX << ' ' << nextY << '\n';
		recursion(nextX, nextY, count + 1);
	}
	isVisited[y][x] = false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR(y, n) {
		FOR(x, m) {
			char c;
			cin >> c;
			if (c == 'H')
				map[y][x] = 0;
			else
				map[y][x] = c - '0';
		}
	}

	recursion(0, 0, 1);
	cout << result;

	return (0);
}