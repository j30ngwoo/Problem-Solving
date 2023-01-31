#include <iostream>
using namespace std;

void input(void);
void find_max(void);
int n, value[301], prev_x[301], prev_o[301], now_x[301];

int main(void)
{
	input();
	find_max();

	return (0);
}

void input(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int i = 0;
	while (++i <= n)
		cin >> value[i];
	
	return ;
}

void find_max(void)
{
	int i = 0;
	while (++i <= n)
	{
		prev_x[i] = now_x[i - 1] + value[i];
		prev_o[i] = prev_x[i - 1] + value[i];
		now_x[i] = max(prev_x[i - 1], prev_o[i - 1]);
	}

	cout << max(prev_x[n], prev_o[n]);

	return ;
}