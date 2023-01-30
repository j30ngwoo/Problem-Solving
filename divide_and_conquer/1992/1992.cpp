#include <iostream>
using namespace std;

void input(void);
void compression(int x, int y, int size);
int image[65][65];
int move_x[4] = {0, 0, 1, 1}, move_y[4] = {0, 1, 0, 1};
int n;

int main(void)
{
	input();
	compression(1, 1, n);

	return (0);
}

void input(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	int i = 0;
	while (++i <= n)
	{
		int j = 0;
		while (++j <= n)
		{
			char input;
			cin >> input;
			image[i][j] = input - '0';
		}
	}

	return;
}

void compression(int x, int y, int size)
{
	int count = 0, i = -1;
	while (++i < size)
	{
		int j = -1;
		while (++j < size)
			count += image[i + x][j + y];
	}

	if (count == 0)
		cout << 0;
	else if (count == size * size)
		cout << 1;
	else
	{
		cout << '(';
		i = -1;
		while (++i < 4)
			compression(x + (move_x[i] * size / 2), y + (move_y[i] * size / 2), size / 2);
		cout << ')';
	}

	return ;
}