#include <iostream>
#include <queue>

using namespace std;

char picture[100][100];
int is_visited[100][100];
int n;
queue<pair<int, int>> bfs_queue;
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

void set_io(void);
void input_data(void);
void count_section(void);
void bfs(int, int, char);
void set_picture(void);

int main(void)
{
	set_io();
	input_data();
	count_section();
	set_picture();
	count_section();
	
	return (0);
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return;
}

void input_data(void)
{
	cin >> n;
	
	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < n)
			cin >> picture[i][j];
	}

	return ;
}

void count_section(void)
{
	int i = -1, bfs_count = 0;
	while (++i < n)
	{
		int j = -1;
		while (++j < n)
		{
			if (!is_visited[i][j])
			{
				bfs(i, j, picture[i][j]);
				bfs_count++;
			}
		}
	}
	cout << bfs_count << ' ';

	return ;
}

void bfs(int x, int y, char color)
{
	bfs_queue.push(make_pair(x, y));
	is_visited[x][y] = 1;

	while (!bfs_queue.empty())
	{
		int i = -1;
		while (++i < 4)
		{
			int now_x = bfs_queue.front().first + move_x[i];
			int now_y = bfs_queue.front().second + move_y[i];

			if (now_x >= 0 && now_x < n && now_y >= 0 && now_y < n && !is_visited[now_x][now_y] && picture[now_x][now_y] == color)
			{
				is_visited[now_x][now_y] = 1;
				bfs_queue.push(make_pair(now_x, now_y));
			}
		}
		bfs_queue.pop();
	}

	return ;
}

void set_picture(void)
{
	fill_n(is_visited[0], 10000, 0);

	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < n)
			if (picture[i][j] == 'G')
				picture[i][j] = 'R';
	}

	return ;
}
