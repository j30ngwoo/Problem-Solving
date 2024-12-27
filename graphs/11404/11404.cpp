#include <iostream>
#define MAX 1000000000

using namespace std;

void input_data(void);
void floyd(void);

int n, m;
int graph[101][101];

int main(void)
{
	input_data();
	floyd();

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	fill(&graph[0][0], &graph[100][101], MAX);

	int i = 0;
	while (++i <= m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a][b] > c)
			graph[a][b] = c;
	}

	return;
}

void floyd(void)
{
	int mid = 0;
	while (++mid <= n)
	{
		int first = 0;
		while (++first <= n)
		{
			int last = 0;
			while (++last <= n)
				graph[first][last] = min(graph[first][last], graph[first][mid] + graph[mid][last]);
		}
	}

	int i = 0;
	while (++i <= n)
	{
		int j = 0;
		while (++j <= n)
		{
			if (i != j && graph[i][j] != MAX)
				cout << graph[i][j];
			else
				cout << 0;
			cout << ' ';
		}
		cout << '\n';
	}

	return ;
}