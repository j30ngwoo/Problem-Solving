#include <iostream>

using namespace std;

int n;
int tiling[1001];

int main(void)
{
	cin >> n;

	tiling[0] = 1;
	tiling[1] = 1;

	int i = 1;
	while (++i <= n)
	{
		tiling[i] = tiling[i - 1] + tiling[i - 2] * 2;
		tiling[i] %= 10007;
	}
	
	cout << tiling[n] << '\n';

	return (0);
}