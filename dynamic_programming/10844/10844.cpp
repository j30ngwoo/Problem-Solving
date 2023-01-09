#include <iostream>

using namespace std;

int n;
int dp[10][100];
int move_x[2] = {1, 1};
int move_y[2] = {1, -1};

void input_data(void);
void stair(void);

int main(void)
{
	input_data();
	stair();

	return (0);
}

void input_data(void)
{
	cin >> n;
	
	int i = -1;
	while (++i < 10)
		dp[i][n - 1] = 1;

	return ;
}

void stair(void)
{
	int x = n - 1;
	
	while (--x >= 0)
	{
		int y = -1;
		while (++y < 10)
		{
			int move = -1;
			while (++move < 2)
			{
				int next_x = x + move_x[move];
				int next_y = y + move_y[move];

				if (next_y >= 0 && next_y < 10)
					dp[y][x] += dp[next_y][next_x];
			}
			dp[y][x] %= 1000000000;
		}
	}

	int i = 0;
	int count = 0;
	while (++i < 10)
	{
		count += dp[i][0];
		count %= 1000000000;
	}
	cout << count << '\n';

	return ;
}