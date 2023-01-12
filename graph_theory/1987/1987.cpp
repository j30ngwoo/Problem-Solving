#include <iostream>

using namespace std;

void input_data(void);
void recursion(int now_y, int now_x);

int r, c, result, count;
int map[20][20];
int is_visited[26];
int move_x[4] = {-1, 1, 0, 0};
int move_y[4] = {0, 0, -1, 1};

int main(void)
{
	input_data();
	recursion(0, -1);
	cout << result << '\n';

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	int i = -1;
	while (++i < r)
	{
		int j = -1;
		while (++j < c)
		{
			char input;
			cin >> input;
			map[i][j] = input - 'A';
		}
	}

	return ;
}

void recursion(int now_y, int now_x)
{
	int i = -1;
	while (++i < 4)
	{
		int next_x = now_x + move_x[i];
		int next_y = now_y + move_y[i];
		
		if (next_x >= 0 && next_x < c && next_y >= 0 && next_y < r && !is_visited[map[next_y][next_x]])
		{
			is_visited[map[next_y][next_x]] = 1;
			count++;
			result = max(count, result);
			recursion(next_y, next_x);
			is_visited[map[next_y][next_x]] = 0;
			count--;
		}
	}

	return ;
}
