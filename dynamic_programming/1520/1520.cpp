#include <iostream>

using namespace std;

void	input_data(void);
int		recursion(int x, int y);

int m, n;
int map[500][500];
int path_count[500][500];
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

int main(void)
{
	input_data();
	cout << recursion(0, 0);

	return (0);
}

void input_data(void)
{
	cin >> m >> n;

	int i = -1;
	while (++i < m)
	{
		int j = -1;
		while (++j < n)
		{
			cin >> map[i][j];
			path_count[i][j] = -1;
		}
	}

	return ;
}

int	recursion(int x, int y)
{
	if (x == m - 1 && y == n - 1)
		return (1);

	if (path_count[x][y] == -1)
	{
		path_count[x][y] = 0;

		int i = -1;
		while (++i < 4)
		{
			int next_x = x + move_x[i];
			int next_y = y + move_y[i];
			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && map[next_x][next_y] < map[x][y])
				path_count[x][y] += recursion(next_x, next_y);
		}
	}

	return (path_count[x][y]);
}