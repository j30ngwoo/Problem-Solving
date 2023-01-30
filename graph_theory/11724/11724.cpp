#include <iostream>
#include <vector>
using namespace std;

void input(void);
void recursion(int now_node);
vector<int> graph[1001];
int n, m, count, is_visited[1001];

int main(void)
{
	input();

	int i = 0;
	while (++i <= n) 
	{
		if (!is_visited[i])
		{
			count++;
			recursion(i);
		}
	}
	cout << count;

	return (0);
}

void input(void)
{
	int u, v;
	cin >> n >> m;
	
	int i = -1;
	while (++i < m)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	return ;
}

void recursion(int now_node)
{
	is_visited[now_node] = 1;
	int i = -1;
	while (++i < graph[now_node].size())
	{
		int next_node = graph[now_node][i];
		if (!is_visited[next_node])
			recursion(next_node);
	}

	return ;
}