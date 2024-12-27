#include <iostream>
#include <queue>

using namespace std;

int n, k, is_visited[100001];
queue<pair<int, int>> bfs_queue;

void set_io(void);
void input_data(void);
int bfs(void);

int main(void)
{
	set_io();
	input_data();
	cout << bfs();

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
	cin >> n >> k;

	return ;
}

int bfs(void)
{
	bfs_queue.push(make_pair(0, n));
	is_visited[n] = 1;

	while (!bfs_queue.empty())
	{
		int now_sec = bfs_queue.front().first;
		int now_location = bfs_queue.front().second;
		bfs_queue.pop();

		if (now_location == k)
			return (now_sec);

		if (now_location <= 50000 && !is_visited[now_location * 2])
		{
			bfs_queue.push(make_pair(now_sec + 1, now_location * 2));
			is_visited[now_location * 2] = 1;
		}

		if (now_location < 100000 && !is_visited[now_location + 1])
		{
			bfs_queue.push(make_pair(now_sec + 1, now_location + 1));
			is_visited[now_location + 1] = 1;
		}

		if (now_location > 0 && !is_visited[now_location - 1])
		{
			bfs_queue.push(make_pair(now_sec + 1, now_location - 1));
			is_visited[now_location - 1] = 1;
		}
	}

	return (-1);
}