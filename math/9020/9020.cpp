#include <iostream>

#define maximum 10000

using namespace std;

void set_io(void);
void eratos(void);
void goldbach(void);

int t, is_prime[maximum];

int main(void)
{
	set_io();
	eratos();

	cin >> t;
	while (--t >= 0)
		goldbach();

	return (0);
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return;
}

void eratos(void)
{
	fill_n(is_prime, maximum, 1);

	int divisor = 1;

	while ((++divisor) * divisor <= maximum)
	{
		int i = 1;

		while (++i * divisor <= maximum)
			is_prime[i * divisor] = 0;
	}

	return ;
}

void goldbach(void)
{
	int n;
	cin >> n;

	int i = -1;
	while (++i >= 0)
	{
		int a = n / 2 - i;
		int b = n / 2 + i;

		if (is_prime[a] && is_prime[b])
		{
			cout << a << ' ' << b << '\n';
			return ;
		}
	}

	return ;
}