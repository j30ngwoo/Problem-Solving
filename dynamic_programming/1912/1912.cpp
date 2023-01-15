#include <iostream>

using namespace std;

void continuous_sum(void);

int n, input, now_max;
int total_max = -1000;

int main(void)
{	
	continuous_sum();

	return (0);
}

void continuous_sum(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int i = -1;
	while (++i < n)
	{
		cin >> input;
		now_max += input;
		if (now_max > total_max)
			total_max = now_max;
		if (now_max < 0)
			now_max = 0;
	}
	cout << total_max;

	return ;
}