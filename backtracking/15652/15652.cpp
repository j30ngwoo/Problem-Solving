#include <iostream>
using namespace std;

void recursion(int now_num, int count);

int n, m, arr[9];

int main(void)
{
	cin >> n >> m;

	int i = 0;
	while (++i <= n)
		recursion(i, 1);

	return (0);
}

void recursion(int now_num, int count)
{
	arr[count] = now_num;

	if (count == m)
	{
		int i = 0;
		while (++i <= m)
			cout << arr[i] << ' ';
		cout << '\n';

		return ;
	}

	int i = now_num - 1;
	while (++i <= n)
		recursion(i, count + 1);

	return ;
}