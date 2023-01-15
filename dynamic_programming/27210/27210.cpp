#include <iostream>

using namespace std;

int n, left_max, right_max, total_max, input;

void find_maximum(void);

int main(void)
{
	find_maximum();

	return (0);
}

void find_maximum(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int i = -1;
	while (++i < n)
	{
		cin >> input;
		input == 1 ? left_max ++ : left_max --;
		input == 2 ? right_max ++ : right_max --;
		if (left_max > total_max || right_max > total_max)
			total_max = max(left_max, right_max);
		if (left_max < 0)
			left_max = 0;
		if (right_max < 0)
			right_max = 0;
	}

	cout << total_max;

	return ;
}