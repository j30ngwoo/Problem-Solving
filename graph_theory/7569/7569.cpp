#include <iostream>
#include <queue>

using namespace std;

void set_io(void);
void input_data(void);
void bfs(void);
void check_tomato(void);

typedef struct{
	int x;
	int y;
	int z;
} coordinate;

int m, n, h;
int box[100][100][100];
queue<coordinate> bfs_queue; 

int main(void)
{
	set_io();
	input_data();
	bfs();
	check_tomato();

	return (0);
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return ;
}

void input_data(void)
{
	cin >> m >> n >> h;

	int z = -1;
	while (++z < h)
	{
		int y = -1;
		while (++y < n)
		{
			int x = -1;
			while (++x < m)
			{
				cin >> box[z][y][x];
				if (box[z][y][x] == 1)
					bfs_queue.push({x, y, z});
			}
		}
	}

	return ;
}

void bfs(void)
{
	while (!bfs_queue.empty())
	{
		int now_x = bfs_queue.front().x;
		int now_y = bfs_queue.front().y;
		int now_z = bfs_queue.front().z;
		bfs_queue.pop();

		if (now_x > 0 && box[now_z][now_y][now_x - 1] == 0)
		{
			bfs_queue.push({now_x - 1, now_y, now_z});
			box[now_z][now_y][now_x - 1] = box[now_z][now_y][now_x] + 1;
		}
		if (now_x < m - 1 && box[now_z][now_y][now_x + 1] == 0)
		{
			bfs_queue.push({now_x + 1, now_y, now_z});
			box[now_z][now_y][now_x + 1] = box[now_z][now_y][now_x] + 1;
		}
		if (now_y > 0 && box[now_z][now_y - 1][now_x] == 0)
		{
			bfs_queue.push({now_x, now_y - 1, now_z});
			box[now_z][now_y - 1][now_x] = box[now_z][now_y][now_x] + 1;
		}
		if (now_y < n - 1 && box[now_z][now_y + 1][now_x] == 0)
		{
			bfs_queue.push({now_x, now_y + 1, now_z});
			box[now_z][now_y + 1][now_x] = box[now_z][now_y][now_x] + 1;
		}
		if (now_z > 0 && box[now_z - 1][now_y][now_x] == 0)
		{
			bfs_queue.push({now_x, now_y, now_z - 1});
			box[now_z - 1][now_y][now_x] = box[now_z][now_y][now_x] + 1;
		}
		if (now_z < h - 1 && box[now_z + 1][now_y][now_x] == 0)
		{
			bfs_queue.push({now_x, now_y, now_z + 1});
			box[now_z + 1][now_y][now_x] = box[now_z][now_y][now_x] + 1;
		}
	}

	return ;
}

void check_tomato(void)
{
	int days = 0;

	int z = -1;
	while (++z < h)
	{
		int y = -1;
		while (++y < n)
		{
			int x = -1;
			while (++x < m)
			{
				//cout << box[z][y][x] << ' ';
				if (box[z][y][x] == 0)
				{
					cout << -1;
					return ;
				}
				else
					days = max(box[z][y][x] - 1, days);
			}
			//cout << '\n';
		}
	}

	cout << days;
	return ;
}