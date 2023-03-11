#include <iostream>

using namespace std;

int n, r, c, flag;

int main()
{
	cin >> n >> r >> c;
	flag = (r + c) % 2;

	int i = 0;
	while (++i <= n)
	{
		int j = 0;
		while (++j <= n)
		{
			if (flag == 0)
				cout << 'v';
			else
				cout << '.';
			flag = !flag;
		}
		cout << '\n';
		if (n % 2 == 0)
			flag = !flag;
	}
}