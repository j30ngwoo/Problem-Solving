#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m, result = 0;
int paper[500][500];
bool isVisited[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void recursion(int len, int value, int x, int y) {
	if (len == 4) {
		result = max(result, value);
		return ;
	}
	FOR (i, 4) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY || isVisited[nextY][nextX])
			continue ;
		isVisited[nextY][nextX] = true;
		recursion(len + 1, value + paper[nextY][nextX], nextX, nextY);
		isVisited[nextY][nextX] = false;
	}
}

void checkTblock(int x, int y) {
	FOR (except, 4) {
		int value = paper[y][x];
		FOR (i, 4) {
			if (i == except)
				continue ;
			int nextX = x + dx[i]; 
			int nextY = y + dy[i];
			if (nextX < 0 || m <= nextX || nextY < 0 || n <= nextY)
				break ;
			value += paper[nextY][nextX];
		}
		result = max(result, value);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (y, n)
		FOR (x, m)
			cin >> paper[y][x];
	
	FOR (y, n)
		FOR (x, m)
			recursion(0, 0, x, y);
	FOR (y, n)
		FOR (x, m)
			checkTblock(x, y);
	
	cout << result;
	return (0);
}