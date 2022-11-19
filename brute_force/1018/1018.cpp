#include <iostream>
#include <vector>

using namespace std;

int		m, n;
int		board[50][50] = {0, };

void	input_data(void);
int		min_square(void);
int		paint_square(int x, int y);
int		count_square(int x, int y, int w_or_b);
int		convert(int a);

int	main(void)
{
	input_data();
	int	result = min_square();
	cout << result;
	
	return (0);
}

void input_data(void)
{
	cin >> m >> n;

	int	i = -1;
	while (++i < m)
	{
		int		j = -1;
		char	c;
		while (++j < n)
		{
			cin >> c;
			if (c == 'B')
				board[i][j] = 1;
		}
	}

	return ;
}

int min_square(void)
{
	int min = paint_square(0, 0);

	int	x = -1;
	while (++x <= m - 8)
	{
		int y = -1, tmp;
		while (++y <= n - 8)
		{
			tmp = paint_square(x, y);
			if (min > tmp)
				min = tmp;
		}
	}
	return (min);
}

int	paint_square(int x, int y)
{
	int w_count = count_square(x, y, 0);
	int b_count = count_square(x, y, 1);

	if (w_count > b_count)
		return (b_count);
	else
		return (w_count);
}

int count_square(int x, int y, int w_or_b)
{
	int count = 0;
	
	int i = -1;
	while(++i < 8)
	{
		int j = -1;
		while(++j < 8)
		{
			if (board[x + i][y + j] != w_or_b)
				count++;
			if (j != 7)
				w_or_b = convert(w_or_b);
		}
	}
	return (count);
}

int convert(int a)
{
	if (a == 1)
		return (0);
	else
		return (1);
}