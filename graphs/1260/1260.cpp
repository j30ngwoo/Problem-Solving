#include <iostream>
#include <queue>

using namespace std;

void input_data(void);
void dfs(int now_node);
void bfs(void);

int graph[1001][1001];
int is_visited[1001];
int n, m, v;
queue<int> bfs_queue;

int main(void)
{
	input_data();
	dfs(v);

	cout << '\n';
	fill_n(is_visited, 1001, 0);

	bfs();

	return (0);
}

void input_data(void)
{
	cin >> n >> m >> v;

	int i = 0;
	while (++i <= m)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	return ;
}

void dfs(int now_node)
{
	is_visited[now_node] = 1;
	cout << now_node << ' ';

	int i = 0;	
	while (++i <= n)
		if (graph[now_node][i] && !is_visited[i])
			dfs(i);

	return ;
}

void bfs(void)
{
	bfs_queue.push(v);
	is_visited[v] = 1;
	
	while (!bfs_queue.empty())
	{
		int now_node = bfs_queue.front();
		bfs_queue.pop();
		cout << now_node << ' ';
		
		int i = 0;
		while (++i <= n)
		{
			if (graph[now_node][i] && !is_visited[i])
			{
				is_visited[i] = 1;
				bfs_queue.push(i);
			}
		}
	}

	return ;
}