#include <iostream>
#include <queue>

using namespace std;

void input(void);
void bfs(void);

vector<int> graph[101];
queue<int> bfs_q;
int n, m;
int is_visited[101];

int main(void)
{
	input();
	bfs();

	return (0);
}

void input(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int i = -1;
	while (++i < m)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	return ;
}

void bfs(void)
{
	bfs_q.push(1);
	is_visited[1] = 1;
	int count = 0;

	while (!bfs_q.empty())
	{
		int now_node = bfs_q.front();
		bfs_q.pop();

		int i = -1;
		while (++i < graph[now_node].size())
		{
			int next_node = graph[now_node][i];
			if (!is_visited[next_node])
			{
				bfs_q.push(next_node);
				is_visited[next_node] = 1;
				count++;
			}
		}
	}

	cout << count << '\n';

	return ;
}