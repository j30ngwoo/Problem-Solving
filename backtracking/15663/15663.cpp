#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
using namespace std;

int n, m, x;
vector<int> arr;
vector<int> result;

void recursion(int index, int layer) {
	if (layer == 0) {
		for (int e : result)
			cout << e << ' ';
		cout << '\n';
		return ;
	}
	for (int i = index; i <= n - layer; i++) {
		result.push_back(arr[i]);
		recursion(i + 1, layer - 1);
		result.pop_back();
	}
}

int main(void) {
	cin >> n >> m;

	FOR (i, n) {
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	recursion(0, m);
	return (0);
}