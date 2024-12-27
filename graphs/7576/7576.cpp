#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void	input_data(void);
int		tomato(void);
int		first_check(void);
void	renew_near_node(int x, int y);
int		last_check(void);
void	prt_arr(void);

int	m, n;
int	boxes[1000][1000];
queue<pair<int, int>> bfs_queue;

int main(void)
{
	input_data();
	int result = tomato();
	cout << result;
	
	return (0);
}

void input_data(void)
{
	cin >> m >> n;
	
	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
			cin >> boxes[i][j];
	}
}

int tomato(void)
{
	int count = 0;

	if (first_check() == 0)
		return (0);

	while (!bfs_queue.empty())
	{
		int now_queue_size = bfs_queue.size();
		while (--now_queue_size >= 0)
		{
			int x = bfs_queue.front().first;
			int y = bfs_queue.front().second;
			bfs_queue.pop();
			renew_near_node(x, y);
		}
		//cout << endl;
		//prt_arr();
		count++;
	}

	if (last_check() == 0)
		return (-1);
	else
		return (count - 1);

}

int first_check(void)
{
	int i = -1;
	int	count_zero = 0;

	while (++i < n)
	{
		int j = -1;
		while (++j < m)
		{
			if (boxes[i][j] == 1)
				bfs_queue.push(make_pair(i, j));
			else if (boxes[i][j] == 0)
				count_zero++;
		}
	}

	if (count_zero == 0)
		return (0);
	else
		return (1);
}

void renew_near_node(int x, int y)
{
	int move_x[4] = {1, -1, 0, 0};
	int move_y[4] = {0, 0, 1, -1};

	int i = -1;
	while (++i < 4)
	{
		int new_x = x + move_x[i];
		int new_y = y + move_y[i];

		if (boxes[new_x][new_y] == 0 && new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)
		{
			boxes[new_x][new_y] = 1;
			bfs_queue.push(make_pair(new_x, new_y));
		}
	}

	return ;
}

int last_check(void)
{
	int i = -1;

	while (++i < n)
	{
		int j = -1;
		while (++j < m)
		{
			if (boxes[i][j] == 0)
				return (0);
		}
	}

	return (1);
}

void prt_arr(void)
{
	int	i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
			cout << boxes[i][j] << " ";
		cout << endl;
	}

	return ;
}