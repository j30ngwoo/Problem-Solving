#include <iostream>
using namespace std;

void find_zero(void);
int n, five, two;

int main(void)
{
	find_zero();

	return (0);
}

void find_zero(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	n++;

	while (--n)
	{
		int now_n = n;
		while (now_n % 5 == 0)
		{
			five++;
			now_n /= 5;
		}
		while (now_n % 2 == 0)
		{
			two++;
			now_n /= 2;
		}
	}
	cout << min(five, two);

	return ;
}