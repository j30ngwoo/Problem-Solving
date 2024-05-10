#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

struct edge {
	int endNode;
	int distance;
};

struct Route {
	bool operator<(const Route& other) const {
		return totalDist > other.totalDist;
	}
	int node;
	int totalDist;
};

int n, e, a, b, c, v1, v2, start_v1, start_v2, v1_v2, v1_end, v2_end;
vector<edge> graph[801];
bool isVisited[801];
priority_queue<Route> pq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	FOR(i, e) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	cin >> v1 >> v2;

	
	// start -> v1
	fill_n(isVisited, 801, false);
	pq.push({1, 0});
	while (!pq.empty()) {
		int nowNode = pq.top().node;
		int totalDist = pq.top().totalDist;
		isVisited[nowNode] = true;
		pq.pop();
		if (nowNode == v1) {
			start_v1 = totalDist;
			break ;
		}
		for (edge nextEdge : graph[nowNode]) {
			int nextNode = nextEdge.endNode;
			int nextDist = nextEdge.distance; 
			if (isVisited[nextNode])
				continue ;
			pq.push({nextNode, totalDist + nextDist});
		}
	}
	while (!pq.empty())
		pq.pop();
	

	// start -> v2
	fill_n(isVisited, 801, false);
	pq.push({1, 0});
	while (!pq.empty()) {
		int nowNode = pq.top().node;
		int totalDist = pq.top().totalDist;
		isVisited[nowNode] = true;
		pq.pop();
		if (nowNode == v2) {
			start_v2 = totalDist;
			break ;
		}
		for (edge nextEdge : graph[nowNode]) {
			int nextNode = nextEdge.endNode;
			int nextDist = nextEdge.distance; 
			if (isVisited[nextNode])
				continue ;
			pq.push({nextNode, totalDist + nextDist});
		}
	}
	while (!pq.empty())
		pq.pop();

	// v1 -> end
	fill_n(isVisited, 801, false);
	pq.push({v1, 0});
	while (!pq.empty()) {
		int nowNode = pq.top().node;
		int totalDist = pq.top().totalDist;
		isVisited[nowNode] = true;
		pq.pop();
		if (nowNode == n) {
			v1_end = totalDist;
			break ;
		}
		for (edge nextEdge : graph[nowNode]) {
			int nextNode = nextEdge.endNode;
			int nextDist = nextEdge.distance; 
			if (isVisited[nextNode])
				continue ;
			pq.push({nextNode, totalDist + nextDist});
		}
	}
	while (!pq.empty())
		pq.pop();
	
	// v2 -> end
	fill_n(isVisited, 801, false);
	pq.push({v2, 0});
	while (!pq.empty()) {
		int nowNode = pq.top().node;
		int totalDist = pq.top().totalDist;
		isVisited[nowNode] = true;
		pq.pop();
		if (nowNode == n) {
			v2_end = totalDist;
			break ;
		}
		for (edge nextEdge : graph[nowNode]) {
			int nextNode = nextEdge.endNode;
			int nextDist = nextEdge.distance; 
			if (isVisited[nextNode])
				continue ;
			pq.push({nextNode, totalDist + nextDist});
		}
	}
	while (!pq.empty())
		pq.pop();

	// v1 -> v2
	fill_n(isVisited, 801, false);
	pq.push({v1, 0});
	while (!pq.empty()) {
		int nowNode = pq.top().node;
		int totalDist = pq.top().totalDist;
		isVisited[nowNode] = true;
		pq.pop();
		if (nowNode == v2) {
			v1_v2 = totalDist;
			break ;
		}
		for (edge nextEdge : graph[nowNode]) {
			int nextNode = nextEdge.endNode;
			int nextDist = nextEdge.distance; 
			if (isVisited[nextNode])
				continue ;
			pq.push({nextNode, totalDist + nextDist});
		}
	}
	while (!pq.empty())
		pq.pop();

	// cout << start_v1 << '\n';
	// cout << start_v2 << '\n';
	// cout << v1_v2 << '\n';
	// cout << v1_end << '\n';
	// cout << v2_end << '\n';

	if (start_v1 == 0 && start_v2 == 0 || v1_v2 == 0 || v1_end == 0 && v2_end == 0)
		cout << -1;
	else
		cout << min(start_v1 + v1_v2 + v2_end, start_v2 + v1_v2 + v1_end);
	return (0);
}