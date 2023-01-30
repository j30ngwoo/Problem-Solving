#include <iostream>

using namespace std;

void set(void);
int dp[2][41];

int main(void)
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set();
	int n;
	cin >> n;
	while (n--)
	{
		int input;
		cin >> input;
		cout << dp[0][input] << ' ' << dp[1][input] << '\n';
	}

	return (0);
}

void set(void)
{
	dp[0][0] = 1;
	dp[1][1] = 1;

	int i = 1;
	while (++i < 41)
	{
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}

	return ;
}