#include <iostream>

using namespace std;

void input_data(void);
void find_max(void);
void prt_square(void);

int n, m, c, total_max;
int student_a[1001], student_b[1001];
int satisfaction[17][17];
int dp[1001][1001];

int main(void)
{
	input_data();
	find_max();

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i, j;

	cin >> n >> m >> c;
	
	i = 0;
	while (++i <= c)
	{
		j = 0;
		while (++j <= c)
			cin >> satisfaction[i][j];
	}

	i = 0;
	while (++i <= n)
		cin >> student_a[i];
	
	i = 0;
	while (++i <= m)
		cin >> student_b[i];

	return ;
}

void find_max(void)
{
	int i, j;
	
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= m)
		{
			int now_value = satisfaction[student_a[i]][student_b[j]] + dp[i - 1][j - 1];
			dp[i][j] = max(now_value, dp[i][j - 1]);
			total_max = max(total_max, dp[i][j]);
			//prt_square();
		}
	}

	cout << total_max << '\n';

	return ;
}

void prt_square(void)
{
	cout << '\n';
	int i = 0;
	while (++i <= n)
	{
		int j = 0;
		while (++j <= m)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	return ;
}