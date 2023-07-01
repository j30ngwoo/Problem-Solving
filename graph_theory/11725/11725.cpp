#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, parent[100001];
vector<int> graph[100001];
queue<int> q;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	q.push(1);
	parent[1] = 1;
	while (!q.empty())
	{
		int now_node = q.front();
		q.pop();
		for (int i = 0; i < graph[now_node].size(); i++)
		{
			int next_node = graph[now_node].at(i);
			if (parent[next_node] == 0)
			{
				parent[next_node] = now_node;
				q.push(next_node);
			}
		}
	}

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';

	return (0);
}