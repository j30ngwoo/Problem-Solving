#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)

using namespace std;

int cTable[1025][1025];
int n, m;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	FOR1(x, n) {
		FOR1(y, n) {
			int value;
			cin >> value;
			cTable[x][y] = value + cTable[x - 1][y] + cTable[x][y - 1] - cTable[x - 1][y - 1];
		}
	}
	FOR1(i, m) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << cTable[x2][y2] - cTable[x2][y1 - 1] - cTable[x1 - 1][y2] + cTable[x1 - 1][y1 - 1] << '\n';
	}
	return (0);
}