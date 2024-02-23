#include <iostream>
#include <vector>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int n, m, result[9];
bool isVisited[9];

void print_arr() {
	FOR(i, m)
		cout << result[i] << ' ';
	cout << '\n';
}

void recursion(int len) {
	if (len == m) {
		print_arr();
		return ;
	}
	FOR1(next, n) {
		if (isVisited[next])
			continue ;
		isVisited[next] = true;
		result[len] = next;
		recursion(len + 1);
		isVisited[next] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	recursion(0);
	return (0);
}