#include <iostream>
#define maximum (123456 * 2 + 1)

using namespace std;


int is_prime[maximum];

void set_io(void);
void eratos(void);
void bertrand(void);

int main(void)
{
	set_io();
	eratos();
	bertrand();	

	return (0);	
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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

void bertrand(void)
{
	while (true)
	{
		int n, cnt = 0;
		cin >> n;
		if (n == 0) 
			return ;

		int i = n;
		while (++i <= 2 * n)
			if (is_prime[i] == 1) 
				cnt++;

		cout << cnt << '\n';
	}

	return ;
}