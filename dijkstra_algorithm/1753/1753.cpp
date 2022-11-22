#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void input_data(void);
void shortest_path(void);
void print_result(void);

vector<vector<pair<int, int>>> graph;
queue<int> bfs_queue;
int	path[20001];
int total_voltex, total_edge, start_voltex;

int main(void)
{
	input_data();
	shortest_path();
	print_result();

	return (0);
}

void input_data(void)
{
	cin >> total_voltex >> total_edge;
	cin >> start_voltex;

	graph.assign(total_voltex + 1, vector<pair<int, int>>(0));
	fill(&path[0], &path[20001], -1);
	path[start_voltex] = 0;

	int	i = 0;
	while (++i <= total_edge)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		graph[u].push_back(make_pair(v, weight));
	}

	return ;
}

void shortest_path(void)
{
	bfs_queue.push(start_voltex);

	while (!bfs_queue.empty())
	{
		int now_voltex = bfs_queue.front();
		bfs_queue.pop();

		int i = -1;
		while (++i < graph[now_voltex].size())
		{
			int target_voltex = graph[now_voltex][i].first;
			int target_weight = graph[now_voltex][i].second;

			if (path[target_voltex] == -1 || path[target_voltex] > path[now_voltex] + target_weight)
			{
				bfs_queue.push(target_voltex);
				path[target_voltex] = path[now_voltex] + target_weight;
			}
		}
	}

	return ;
}

void print_result(void)
{
	int i = 0;

	while (++i <= total_voltex)
	{
		if (path[i] == -1)
			cout << "INF" << endl;
		else
			cout << path[i] << endl;
	}

	return ;
}