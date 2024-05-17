#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
using namespace std;

int n, m, x;
bool isSelected[9];
vector<int> arr;
vector<int> result;
set<vector<int>> resultSet;

void recursion(int index, int layer) {
	if (layer == 0) {
		resultSet.insert(result);
		return ;
	}
	for (int i = 0; i < n; i++) {
		if (isSelected[i])
			continue;
		result.push_back(arr[i]);
		isSelected[i] = true;
		recursion(i + 1, layer - 1);
		result.pop_back();
		isSelected[i] = false;
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
	vector<vector<int>> resultVector(resultSet.begin(), resultSet.end());
	sort(resultVector.begin(), resultVector.end());
	for (vector<int> v : resultVector) {
		for (int e : v)
			cout << e << ' ';
		cout << '\n';
	}
	return (0);
}