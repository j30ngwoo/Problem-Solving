#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;
int graph[100][100];
int n;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	FOR(from, n) {
		FOR(to, n) {
			int input;
			cin >> input;
			graph[from][to] = input;
		}
	}
	
	FOR(mid, n)
		FOR(first, n)
			FOR(last, n)
				if (graph[first][mid] == 1 && graph[mid][last] == 1)
					graph[first][last] = 1;

	FOR(from, n) {
		FOR(to, n) {
			cout << graph[from][to] << ' ';
		}
		cout << '\n';
	}

	return (0);
}