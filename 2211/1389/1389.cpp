#include <iostream>
#include <queue>
#define MAX 

using namespace std;

void	input_data(void);
void	print_graph(vector<vector<int>> &graph);
int		find_min_bacon(void);
int		sum_of_bacon(int now_node);
int 	bfs(int	now_node, int target_node);

vector<vector<int>>	graph;
vector<int>			node_depth;
queue<int>			bfs_queue;
int					node, edge;

int main(void)
{
	input_data();
	//print_graph(graph);
	int	result = find_min_bacon();
	cout << result;
	return (0);
}

void input_data(void)
{
	cin >> node >> edge;

	graph.assign(node + 1, vector<int>(0));
	node_depth.assign(node + 1, 0);

	int i = -1;
	while (++i < edge)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	return ;
}

void print_graph(vector<vector<int>> &graph)
{
	int i = 0;

	while (++i < graph.size())
	{
		int j = -1;
		cout << i << ": ";
		while (++j < graph[i].size())
			cout << graph[i][j] << " ";
		cout << endl;
	}
}

int	find_min_bacon(void)
{
	int	min_bacon, now_node, min_node;

	now_node = 1;
	min_bacon = sum_of_bacon(now_node);
	min_node = 1;
	while (++now_node < node + 1)
	{
		int	sum;

		sum = sum_of_bacon(now_node);
		if (min_bacon > sum)
		{
			min_bacon = sum;
			min_node = now_node;
		}
	}
	return (min_node);
}

int	sum_of_bacon(int now_node)
{
	int	sum, target_node;

	sum = 0;	
	target_node = 0;
	while (++target_node < node + 1)
	{
		if (now_node != target_node)
		{
			//cout << "@@@bfs start sum = " << sum << endl;
			sum += bfs(now_node, target_node);
			//cout << "@@@bfs end sum = " << sum << endl << endl;
			fill(node_depth.begin(), node_depth.end(), 0);
			while (!bfs_queue.empty())
				bfs_queue.pop();
		}
	}
	return (sum);
}

int bfs(int	now_node, int target_node)
{
	bfs_queue.push(now_node);
	node_depth[now_node] = 1;

	//cout << "@@@now: " << now_node << " target: " << target_node << endl;
	while(1)
	{
		int	i = -1;
		now_node = bfs_queue.front();
		bfs_queue.pop();
		while (++i < graph[now_node].size())
		{
			int	next_node = graph[now_node][i];
			if (next_node == target_node)
				return (node_depth[now_node]);
			if (next_node > 0 && node_depth[next_node] == 0)
			{
				bfs_queue.push(next_node);
				//cout << "@@@now: " << now_node << " next: " << next_node << endl;
				node_depth[next_node] = node_depth[now_node] + 1;
			}
		}
	}
	return(-1);
}