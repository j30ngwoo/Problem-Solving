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
		if (nowN * 10 + 1 <= 10000000000)
			q.push({nowN * 10 + 1, nowCount + 1});
		if (nowN * 2 <= 1000000000)
			q.push({nowN * 2, nowCount + 1});
	}
	cout << -1;
	return (0);
}