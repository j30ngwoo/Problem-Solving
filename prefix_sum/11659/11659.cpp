#include <iostream>
using namespace std;

int n, m;
int sum[100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	int i = 0;
	while (++i <= n)
	{
		int input;
		cin >> input;
		sum[i] = sum[i - 1] + input;
	}

	i = -1;
	while (++i < m)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}

	return (0);
}