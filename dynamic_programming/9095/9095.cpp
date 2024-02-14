#include <iostream>
#include <vector>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int t, n, count = 0;
vector<int> v;

void recursion(int remain) {
	if (remain == 0)
		count++;
	FOR1(sub, 3) {
		if (remain - sub >= 0) {
			v.push_back(sub);
			recursion(remain - sub);
			v.pop_back();
		}
	}
}

int main(void) {
	cin >> t;
	FOR(i, t) {
		cin >> n;
		count = 0;
		recursion(n);
		cout << count << '\n';
	}
	return (0);
}