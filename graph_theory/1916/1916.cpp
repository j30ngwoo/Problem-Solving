#include <iostream>
#include <queue>
#define INF 2e9
using namespace std;

void input(void);
void dijkstra(void);

int n, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;
vector<pair<int, int>> graph[1001];
int weight[1001];

int main(void)
{
	input();
	dijkstra();

	return (0);
}

void input(void)
{
	cin >> n >> m;
	int i = -1;
	while (++i < m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}
	fill(weight, weight + n + 1, INF);

	return ;
}

void dijkstra(void)
{
	int start, end;
	cin >> start >> end;

	p_q.push({0, start});
	weight[start] = 0;

	while (!p_q.empty())
	{
		int now_node = p_q.top().second;
		int now_weight = p_q.top().first;
		p_q.pop();

		if (weight[now_node] < now_weight)
			continue;
		
		int i = -1;
		while (++i < graph[now_node].size())
		{
			int next_node = graph[now_node][i].first;
			int next_weight = now_weight + graph[now_node][i].second;
			if (next_weight < weight[next_node])
			{
				weight[next_node] = next_weight;
				p_q.push({next_weight, next_node});
			}
		}
	}

	cout << weight[end];

	return ;
}