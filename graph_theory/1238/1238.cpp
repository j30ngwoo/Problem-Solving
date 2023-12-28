#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define INF INT32_MAX

using namespace std;

struct Node {
	int dist;
	int id;
};

int homeToX[1001];
int xToHome[1001];
bool isMinFound[1001];
priority_queue<Node, vector<Node>, greater<Node>> pq;

int n, m, x;

int main(void) {
	cin >> n >> m >> x;
	vector<vector<Node>> graph(n + 1);

	FOR1(home, n) {
		int begin, end, time;
		cin >> begin >> end >> time;
		graph[begin].push_back({end, time});
	}
	
	FOR1(home, n) {
		fill_n(isMinFound, isMinFound + 1001, false);
		while(!pq.empty())
			pq.pop();
		pq.push({0, home});
		isMinFound[home] = true;
		while(!pq.empty()) {
			int id = pq.top().id;
			int dist = pq.top().dist;
			pq.pop();
			if (isMinFound[id]) continue;
			isMinFound[id] = true;
			if (id == x) {
				homeToX[id] = dist;
				break;
			}
			for (Node nextNode : graph[id]) {
				pq.push({dist + nextNode.dist, nextNode.id});
			}
		}
	}

	fill_n(isMinFound, isMinFound + 1001, false);
	while(!pq.empty())
		pq.pop();
	pq.push({0, x});
	isMinFound[x] = true;
	while(!pq.empty()) {
		int id = pq.top().id;
		int dist = pq.top().dist;
		pq.pop();
		if (isMinFound[id]) continue;
		isMinFound[id] = true;
		xToHome[id] = dist;
		for (Node nextNode : graph[id]) {
			pq.push({dist + nextNode.dist, nextNode.id});
		}
	}

	int maximum = -1;
	FOR1(i, n)
		maximum = max(maximum, homeToX[i] + xToHome[i]);
	cout << maximum;
	return (0);
}