#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void input_data(void);
void find_min(void);

vector<pair<int, int>> wire;
int dp[500];
int n;

int main(void)
{
	input_data();
	find_min();

	return (0);
}

void input_data(void)
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int i = -1;
	while (++i < n)
	{
		int a, b;
		cin >> a >> b;
		wire.push_back({a, b});
	}
	sort(wire.begin(), wire.end());

	return ;
}

void find_min(void)
{
	int total_max = 0;
	int now_index = -1;
	while (++now_index < n)
	{
		int last_max = 0;
		int prev_index = -1;
		while (++prev_index < now_index)
			if (wire[prev_index].second < wire[now_index].second)
				last_max = max(last_max, dp[prev_index]);
		dp[now_index] = last_max + 1;
		total_max = max(total_max, dp[now_index]);
	}

	cout << n - total_max << '\n';

	return ;
}