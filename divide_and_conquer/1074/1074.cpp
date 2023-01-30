#include <iostream>
#include <cmath>

using namespace std;

void z(int size);
int n, r, c, result;

int main(void)
{
	cin >> n >> r >> c;
	z(pow(2, n) / 2);

	return (0);
}

void z(int size)
{
	if (size == 0)
	{
		cout << result;
		return ;
	}

	if (r < size && c >= size)
	{
		result += size * size;
		c -= size;
	}
	else if (r >= size && c < size)
	{
		result += size * size * 2;
		r -= size;
	}
	else if (r >= size && c >= size)
	{
		result += size * size * 3;
		c -= size;
		r -= size;
	}
	z(size / 2);

	return ;
}