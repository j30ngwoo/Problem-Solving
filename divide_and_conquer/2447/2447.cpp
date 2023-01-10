#include <iostream>

using namespace std;

void recursion(int, int, int);

int main(void)
{
	int n;
	cin >> n;

	int i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < n)
			recursion(i, j, n);
		cout << '\n';
	}

	return (0);
}

void recursion(int i, int j, int n)
{
	if (n == 1)
		cout << '*';
	else if ((i / (n / 3)) % 3 == 1 && (j / (n / 3)) % 3 == 1)
		cout << ' ';
	else
		recursion(i, j, n / 3);

	return ;
}