#include <iostream>
#include <cstring>
using namespace std;

void find_max(void);

char str1[1002], str2[1002];
int dp[1001][1001], result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	find_max();
	
	return (0);
}

void find_max(void)
{
	cin >> str1 + 1 >> str2 + 1;
	
	int i = 0;
	while (str2[++i])
	{
		int j = 0;
		while (str1[++j])
		{
			if (str2[i] == str1[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[strlen(str2 + 1)][strlen(str1 + 1)];

	return ;
}