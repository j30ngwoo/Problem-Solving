#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[100001];
int visited[100001];
int biggest_weight = 0, biggest_node = 0, n;

void find_biggest(int now_node, int until_weight)
{
	visited[now_node] = 1;
	if (until_weight > biggest_weight)
	{
		biggest_weight = until_weight;
		biggest_node = now_node;
	}
	for (int i = 0; i < graph[now_node].size(); i++)
	{
		int next_node = graph[now_node].at(i).first;
		int next_weight = until_weight + graph[now_node].at(i).second;
		if (!visited[next_node])
			find_biggest(next_node, next_weight);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int node_num;
		cin >> node_num;
		while (1)
		{
			int v, w;
			cin >> v;
			if (v == -1)
				break;
			cin >> w;
			graph[node_num].push_back({v, w});
			graph[v].push_back({node_num, w});
		}
	}
	
	find_biggest(1, 0);
	biggest_weight = 0;
	fill_n(visited, 100001, 0);
	find_biggest(biggest_node, 0);
	cout << biggest_weight;
	return (0);
}