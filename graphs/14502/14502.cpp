#include <iostream>
#include <queue>

using namespace std;

void input_data(void);
void find_maximum(void);
int safety_count(int wall_1, int wall_2, int wall_3);

int n, m, result;
int original_map[8][8];
int copy_map[8][8];
vector<pair<int, int>> empty_coordinate;
vector<pair<int, int>> virus_coordinate;
queue<pair<int, int>> bfs_queue;
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main(void)
{
	input_data();
	find_maximum();

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
			cin >> original_map[i][j];
			if (original_map[i][j] == 0)
				empty_coordinate.push_back({i, j});
			else if (original_map[i][j] == 2)
				virus_coordinate.push_back({i, j});
		}
	}

	return ;
}

void find_maximum(void)
{
	int empty_size = empty_coordinate.size();
	int wall_1 = -1;
	while (++wall_1 < empty_size - 2)
	{
		int wall_2 = wall_1;
		while (++wall_2 < empty_size - 1)
		{
			int wall_3 = wall_2;
			while (++wall_3 < empty_size)
				result = max(result, safety_count(wall_1, wall_2, wall_3));
		}
	}

	cout << result << '\n';

	return ;
}

int safety_count(int wall_1, int wall_2, int wall_3)
{
	copy(&original_map[0][0], &original_map[0][0] + 64, &copy_map[0][0]);
	copy_map[empty_coordinate[wall_1].first][empty_coordinate[wall_1].second] = 1;
	copy_map[empty_coordinate[wall_2].first][empty_coordinate[wall_2].second] = 1;
	copy_map[empty_coordinate[wall_3].first][empty_coordinate[wall_3].second] = 1;

	int i = -1;
	while (++i < virus_coordinate.size())
		bfs_queue.push(virus_coordinate[i]);

	while (!bfs_queue.empty())
	{
		int now_x = bfs_queue.front().second;
		int now_y = bfs_queue.front().first;
		bfs_queue.pop();

		i = -1;
		while (++i < 4)
		{
			int next_x = now_x + move_x[i];
			int next_y = now_y + move_y[i];
			if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && copy_map[next_y][next_x] == 0)
			{
				bfs_queue.push({next_y, next_x});
				copy_map[next_y][next_x] = 2;
			}
		}	
	}

	int count = 0;
	i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < m)
			if (copy_map[i][j] == 0)
				count++;
	}

	return (count);
}