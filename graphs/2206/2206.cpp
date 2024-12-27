#include <iostream>
#include <queue>

using namespace std;

void input_data(void);
void find_shortest(void);
void prt_map(void);

typedef struct {
	int x;
	int y;
	int broken;
} coordinate;

int n, m;
int map[1000][1000];
int broke_map[1000][1000];
queue<coordinate> bfs_queue;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main(void)
{
	input_data();
	find_shortest();
	//prt_map();

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
		{
			char input;
			cin >> input;
			if (input == '1')
				map[i][j] = broke_map[i][j] = -1;	
		}
	}
	
	return ;
}

void find_shortest(void)
{
	bfs_queue.push({0, 0, 0});
	map[0][0] = 1;

	while (!bfs_queue.empty())
	{
		int now_x = bfs_queue.front().x;
		int now_y = bfs_queue.front().y;
		int i = -1;
		while (++i < 4)
		{
			int next_x = now_x + move_x[i];
			int next_y = now_y + move_y[i];
			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
			{
				if (map[next_y][next_x] == 0 && bfs_queue.front().broken == 0)
				{
					bfs_queue.push({next_x, next_y, 0});
					map[next_y][next_x] = map[now_y][now_x] + 1;
				}
				else if (broke_map[next_y][next_x] == 0 && bfs_queue.front().broken == 1)
				{
					bfs_queue.push({next_x, next_y, 1});
					broke_map[next_y][next_x] = broke_map[now_y][now_x] + 1;
				}
				else if (map[next_y][next_x] == -1 && bfs_queue.front().broken == 0)
				{
					bfs_queue.push({next_x, next_y, 1});
					broke_map[next_y][next_x] = map[now_y][now_x] + 1;
				}
			}
		}
		bfs_queue.pop();
	}

	if (map[n - 1][m - 1] == 0)
		map[n - 1][m - 1] = 2000000;
	if (broke_map[n - 1][m - 1] == 0)
		broke_map[n - 1][m - 1] = 2000000;

	if (map[n - 1][m - 1] == 2000000 && broke_map[n - 1][m - 1] == 2000000)
		cout << -1 << '\n';
	else
		cout << min(map[n - 1][m - 1], broke_map[n - 1][m - 1]) << '\n';

	return ;
}

void prt_map(void)
{
	cout << '\n';
	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
			cout << map[i][j];
		cout << '\n';
	}
	cout << '\n';

	i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
			cout << broke_map[i][j];
		cout << '\n';
	}

	return ;
}