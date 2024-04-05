#include <iostream>
#include <vector>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, m, knowPeople, result;
int parent[51];
vector<int> party[50];

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
		_union(p, 0);
	}

	FOR(partyID, m) {
		int NumberOfpartyPeople;
		cin >> NumberOfpartyPeople;
		FOR(i, NumberOfpartyPeople) {
			int p;
			cin >> p;
			party[partyID].push_back(p);
		}
	}

	FOR(partyID, m)
		FOR(i, party[partyID].size() - 1)
			_union(party[partyID][i], party[partyID][i + 1]);

	FOR(partyID, m) {
		bool validFlag = true;
		FOR(i, party[partyID].size()) {
			if (find(0) == find(party[partyID][i])) {
				validFlag = false;
				break ;
			}
		}
		if (validFlag == true)
			result++;
	}

	cout << result;
	return (0);
}