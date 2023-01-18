#include <iostream>

using namespace std;

void eratos(void);

int m, n;
int isnt_prime[1000001] = {1, 1};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	eratos();

	return (0);
}

void eratos(void)
{
	cin >> m >> n;

	int i = 1;
	while (++i <= 1000)
	{
		int j = 1;
		while ((++j) * i <= 1000000)
			isnt_prime[i * j] = 1;
	}

	i = m - 1;
	while (++i <= n)
		if (isnt_prime[i] == 0)
			cout << i << '\n';

	return ;
}