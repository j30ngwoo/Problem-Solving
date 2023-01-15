#include <iostream>

using namespace std;

void input_data(void);
void find_sum(void);
//void prt_map(void);

int n, m, k;
int sum_map[301][301];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	input_data();
	find_sum();

	return (0);
}

void input_data(void)
{
	cin >> n >> m;

	int i = 0;
	while (++i <= n)
	{
		int j = 0;
		while (++j <= m)
		{
			cin >> sum_map[i][j];
			sum_map[i][j] += sum_map[i - 1][j] + sum_map[i][j - 1] - sum_map[i - 1][j - 1];
			//prt_map();
		}
	}
}

void find_sum(void)
{
	cin >> k;

	int i = -1;
	while (++i < k)
	{
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		cout << sum_map[x][y] - sum_map[x][b - 1] - sum_map[a - 1][y] + sum_map[a - 1][b - 1] << '\n';
	}

	return ;
}

void prt_map(void)
{
	int i = -1;
	while (++i <= n)
	{
		int j = -1;
		while (++j <= m)
			cout << sum_map[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n' << '\n';
}