#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i, n) for(int i = 0; i < n; i++)

struct Node {
	int id;
	int dist;	
};

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	vector<vector<int>> graph(n + 1);
	vector<bool> visited(n + 1, false);
	vector<int> result;
	queue<Node> q;

	FOR(i, m) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	q.push({x, 0});
	visited[x] = true;
	while (!q.empty()) {
		Node node = q.front(); q.pop();
		int id = node.id;
		int dist = node.dist;
		if (dist == k)
			result.push_back(id);
		for (auto nextId: graph[id]) {
			if (!visited[nextId]) {
				visited[nextId] = true;
				q.push({nextId, dist + 1});
			}
		}
	}

	if (result.size() == 0) {
		cout << -1;
	} else {
		sort(result.begin(), result.end());
		for (auto id: result)
			cout << id << '\n';
	}
}