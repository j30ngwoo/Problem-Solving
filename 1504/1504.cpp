#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct edge {
	int endNode;
	int distance;
};

struct route {
	bool operator()(const route& a, const route& b) {
		return a.distance > b.distance;
	}
	int node;
	int distance;
};



int n, e, a, b, c, V1, V2, startToV1, startToV2, V1ToV2, V1ToEnd, V2ToEnd;
vector<edge> graph[801];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	FOR(i, e) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[c].push_back({a, c});
	}

	priority_queue<route> pq;
	pq.

	cout << min(startToV1 + V1ToV2 + V2ToEnd, startToV2 + V1ToV2 + V1ToEnd);
	return (0);
}