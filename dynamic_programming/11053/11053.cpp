#include <iostream>

using namespace std;

void find_max(void);

int arr[1001], dp[1001];
int n, result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	find_max();

	return (0);
}

void find_max(void)
{
	cin >> n;
	int now_index = -1;
	while (++now_index < n)
	{
		cin >> arr[now_index];
		
		int last_max = 0;
		int prev_index = -1;
		while (++prev_index < now_index)
			if (arr[prev_index] < arr[now_index])
				last_max = max(last_max, dp[prev_index]);
		dp[now_index] = last_max + 1;
		result = max(dp[now_index], result);
	}

	cout << result << '\n';

	return ;
}