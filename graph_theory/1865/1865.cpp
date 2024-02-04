#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

struct edge {
	int end;
	int time;
};

int tc, n, m, w, s, e, t;

void testcase() {
	cin >> n >> m >> w;
	vector<edge> graph[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;
		graph[s].push_back({e, t});
		graph[e].push_back({s, t});
	}
	int dist[n + 1];
	fill_n(dist, n + 1, 0);
	dist[s] = 0;

	for (int i = 0; i < w; i++) {
		cin >> s >> e >> t;
		graph[s].push_back({e, -t});
	}
	for (int i = 0; i < n - 1; i++) {
		for (int node = 1; node <= n; node++) {
			for (edge edge : graph[node]) {
				//cout << "start: " << node << " end: " << edge.end << '\n';
				if (dist[edge.end] > dist[node] + edge.time) {
					dist[edge.end] = dist[node] + edge.time;
				}
			}
		}
		//cout << "try: " << i << '\n';
		//for (int d = 1; d <= n; d++) cout << dist[d] << '\n';
	}
	for (int node = 1; node <= n; node++) {
		for (edge edge : graph[node]) {
			if (dist[edge.end] > dist[node] + edge.time) {
				cout << "YES\n";
				return ;
			}
		}
	}
	cout << "NO\n";
}

int main(void) {
	cin >> tc;
	for (int tcIndex = 0; tcIndex < tc; tcIndex++)
		testcase();
	return (0);
}
