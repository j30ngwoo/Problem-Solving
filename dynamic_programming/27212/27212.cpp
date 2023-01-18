#include <iostream>

using namespace std;

void input_data(void);
void find_max(void);

int n, m, c;
int student_a[1001], student_b[1001];
int satisfaction[17][17];
long long dp[1001][1001];

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
			long long now_value = satisfaction[student_a[i]][student_b[j]] + dp[i - 1][j - 1];
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = max(dp[i][j], now_value);
		}
	}

	cout << dp[n][m] << '\n';

	return ;
}