#include <iostream>
#include <queue>

using namespace std;

void input_data(void);
void find_section(void);
void bfs(int x, int y);

int n, m, bfs_count;
int planet[1001][1001];
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};
queue<pair<int, int>> bfs_q;

int main(void)
{
	input_data();
	find_section();

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
		{
			cin >> planet[i][j];
			planet[i][j] *= -1;
		}
	}

	return ;
}

void find_section(void)
{
	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
			if (planet[i][j] == 0)
			{
				bfs_count++;
				bfs(i, j);
			}
	}

	cout << bfs_count << '\n';

	return ;
}

void bfs(int x, int y)
{
	bfs_q.push({x, y});
	planet[x][y] = 1;
	
	while (!bfs_q.empty())
	{
		int now_x = bfs_q.front().first;
		int now_y = bfs_q.front().second;
		bfs_q.pop();
		
		int i = -1;
		while (++i < 4)
		{
			int next_x = now_x + move_x[i];
			int next_y = now_y + move_y[i];
			if (next_x < 0)
				next_x = n - 1;
			else if (next_x >= n)
				next_x = 0;
			if (next_y < 0)
				next_y = m - 1;
			else if (next_y >= m)
				next_y = 0;
			if (planet[next_x][next_y] == 0)
			{
				planet[next_x][next_y] = 1;
				bfs_q.push({next_x, next_y});
			}
		}
	}
	
	return ;
}