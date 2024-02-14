#include <iostream>
#include <stack>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
stack<int> s[4];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(i, 4)
		s[i].push(0);

	FOR(i, n) {
		int e, max = -1, maxStackIndex = -1;
		cin >> e;
		FOR(stackIndex, 4) {
			int nowTop = s[stackIndex].top();
			if (nowTop < e && max < nowTop) {
				max = nowTop;
				maxStackIndex = stackIndex;
			}
		}
		if (maxStackIndex == -1) {
			cout << "NO";
			return (0);
		}
		s[maxStackIndex].push(e);
	}
	cout << "YES";
	return (0);
}