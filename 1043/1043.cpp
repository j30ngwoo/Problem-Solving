#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

int n, m, knowPeople, partyPeople;
int parent[51];
bool knowTrue[51];

int find(int child) {
	if (parent[child] == child) 
		return child;
	return parent[child] = find(parent[child]);
} 

void _union(int a, int b) {
	parent[find(a)] = find(b);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	FOR(i, 51)
		parent[i] = i;
	cin >> n >> m >> knowPeople;
	FOR(i, knowPeople) {
		int p;
		cin >> p;
		_union(p, 0); // 0과 같은 set이라면, 진실을 안다.
	}

	FOR(i, m) {
		int p;
		cin >> p;
		FOR(j, p) {
			cin >> 
		}
	}


	return (0);
}