#include <iostream>
#include <algorithm>
using namespace std;

void	input_data(void);
int		find_max_value(void);
void	print_arr(void);

int dp[100001] = {0, };
int weight[100];
int value[100];
int	n, max_weight;

int	main(void)
{
	input_data();
	int result = find_max_value();
	cout << result;

	return (0);
}

void input_data(void)
{
	cin >> n >> max_weight;
	
	int i = -1;
	while (++i < n)
	{
		int	w, v;
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}

	return ;
}

int	find_max_value(void)
{
	int	i = -1;
	while (++i < n)
	{
		int check_weight = max_weight + 1;
		while (--check_weight >= 1)
			if (check_weight >= weight[i])
				dp[check_weight] = max(dp[check_weight], dp[check_weight - weight[i]] + value[i]);
		//print_arr();
	}

	return (dp[max_weight]);
}

void print_arr(void)
{
	int i = 0;
	while (++i < max_weight + 1)
		cout << dp[i] << " ";
	cout << endl;

	return ;
}