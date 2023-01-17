#include <iostream>

using namespace std;

int paper[101][101];
int n;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int i = -1;
	while (++i < n)
	{
		int x, y;
		cin >> x >> y;
		int j = -1;
		while (++j < 10)
		{
			int k = -1;
			while (++k < 10)
				paper[x + j][y + k] = 1;
		}
	}

	int count = 0;
	i = 0;
	while (++i <= 100)
	{
		int j = 0;
		while (++j <= 100)
			if (paper[i][j] == 1)
				count++;
	}

	cout << count;

	return (0);
}