#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void	input_data(void);
int		find_min(void);

int start, goal;
int is_visited[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_queue;

int main(void)
{
	input_data();
	cout << find_min();

	return (0);
}

void input_data(void)
{
	cin >> start >> goal;
	fill(is_visited, is_visited + 100001, 0);

	return ;
}

int find_min(void)
{
	p_queue.push(make_pair(0, start));
	is_visited[start] = 1;

	while (!p_queue.empty())
	{
		int now_sec = p_queue.top().first;
		int now_location = p_queue.top().second;
		int next_location;
		p_queue.pop();

		//cout << now_location << ' ' << now_sec << '\n';

		if (now_location == goal)
			return (now_sec);

		next_location = now_location * 2;
		if (next_location <= 100000 && is_visited[next_location] == 0)
		{
			p_queue.push(make_pair(now_sec, next_location));
			is_visited[next_location] = 1;
		}

		next_location = now_location + 1;
		if (next_location <= 100000 && is_visited[next_location] == 0)
		{
			p_queue.push(make_pair(now_sec + 1, next_location));
			is_visited[next_location] = 1;
		}

		next_location = now_location - 1;
		if (next_location >= 0 && is_visited[next_location] == 0)
		{
			p_queue.push(make_pair(now_sec + 1, next_location));
			is_visited[next_location] = 1;
		}
	}

	return (-1);
}