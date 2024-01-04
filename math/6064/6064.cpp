#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int n;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(i, n) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int d1 = 0, d2 = 0;
		while (true) {
			if (m * d1 + x == n * d2 + y) {
				cout << m * d1 + x << '\n';
				break ;
			}
			if (d1 > n || d2 > m) {
				cout << -1 << '\n';
				break ;
			}
			if (m * d1 + x < n * d2 + y)
				++d1;
			else
				++d2;
		}
	}
	return (0);
}

