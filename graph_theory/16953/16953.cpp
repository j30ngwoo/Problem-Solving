#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct E {
	ll n;
	ll count;
};

queue<E> q;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	q.push({a, 1});
	while (!q.empty()) {
		ll nowN = q.front().n;
		ll nowCount = q.front().count;
		q.pop();
		if (nowN == b) {
			cout << nowCount;
			return (0);
		}
		ll nextCount = nowCount + 1;
		ll nextN = nowN * 10 + 1;
		if (nextN <= 10000000000)
			q.push({nextN, nextCount});
		nextN = nowN * 2;
		if (nextN <= 1000000000)
			q.push({nextN, nextCount});
	}
	cout << -1;
	return (0);
}