#include <iostream>
#include <algorithm>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define WHITE 0
#define BLUE 1
using namespace std;

int n, white, blue;
int accum[129][129];

void recursion(int x, int y, int nowN) {
	int accumSum = accum[y][x] - accum[y - nowN][x] - accum[y][x - nowN] + accum[y - nowN][x - nowN];
	if (accumSum == 0) {
		++white;
		return;
	}
	if (accumSum == nowN * nowN) {
		++blue;
		return;
	}
	int nextN = nowN / 2;
	recursion(x, y, nextN);
	recursion(x - nextN, y, nextN);
	recursion(x, y - nextN, nextN);
	recursion(x - nextN, y - nextN, nextN);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR1(y, n) {
		FOR1(x, n) {
			cin >> accum[y][x];
			accum[y][x] += accum[y - 1][x] + accum[y][x - 1] - accum[y - 1][x - 1];
		}
	}
	
	recursion(n, n, n);
	cout << white << '\n' << blue;

	return (0);
}
