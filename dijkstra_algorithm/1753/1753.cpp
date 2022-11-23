#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void input_data(void);
void shortest_path(void);
void print_result(void);

vector<vector<pair<int, int>>> graph;

int	path[20001];
int total_voltex, total_edge, start_voltex;

struct cmp
{
  	bool operator() (int a, int b) 
	{
		return path[a] > path[b];
	}
};

priority_queue<int, vector<int>, cmp> p_queue;

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
	p_queue.push(start_voltex);
	path[start_voltex] = 0;
	
	while (!p_queue.empty())
	{
		int now_voltex = p_queue.top();
		p_queue.pop();

		int i = -1;
		int now_edges = graph[now_voltex].size();
		while (++i < now_edges)
		{
			int target_voltex = graph[now_voltex][i].first;
			int target_weight = graph[now_voltex][i].second;

			if (path[target_voltex] == -1 || path[target_voltex] > path[now_voltex] + target_weight)
			{
				path[target_voltex] = path[now_voltex] + target_weight;
				p_queue.push(target_voltex);
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
			cout << "INF";
		else
			cout << path[i];
		cout << '\n';
	}

	return ;
}