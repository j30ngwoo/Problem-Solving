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
	bool operator<(const Node &d) const {
		return dist > d.dist;
	}
};

priority_queue<Node> pq;
int n, m, x;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	vector<int> homeToX(n + 1, INF);
	vector<int> xToHome(n + 1, INF);
	vector<vector<Node>> graph(n + 1);
	vector<vector<Node>> revGraph(n + 1);

	FOR1(home, m) {
		int begin, end, time;
		cin >> begin >> end >> time;
		graph[begin].push_back({time, end});
		revGraph[end].push_back({time, begin});
	}	

	pq.push({0, x});
	while(!pq.empty()) {
		int id = pq.top().id;
		int dist = pq.top().dist;
		pq.pop();
		if (xToHome[id] < dist) continue;
		xToHome[id] = dist;
		for (Node nextNode : graph[id]) {
			if (xToHome[nextNode.id] < nextNode.dist) continue;
			pq.push({dist + nextNode.dist, nextNode.id});
		}
	}
	
	pq.push({0, x});
	while(!pq.empty()) {
		int id = pq.top().id;
		int dist = pq.top().dist;
		pq.pop();
		if (homeToX[id] < dist) continue;
		homeToX[id] = dist;	
		for (Node nextNode : revGraph[id]) {
			if (homeToX[nextNode.id] < nextNode.dist) continue;
			pq.push({dist + nextNode.dist, nextNode.id});
		}
	}

	int maximum = 0;
	FOR1(i, n)
		maximum = max(maximum, homeToX[i] + xToHome[i]);
	cout << maximum;
	return (0);
}