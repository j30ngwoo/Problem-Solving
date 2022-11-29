#include <iostream>
#include <vector>

using namespace std;

void	input_data(void);
int		remote_con(void);
int		find_min(void);
int		check_broken(int channel);
int		check_digit(int channel);

int goal, m;
vector<int> broken(0);

int main(void)
{
	input_data();
	cout << remote_con();

	return (0);
}

void input_data(void)
{
	cin >> goal;
	cin >> m;

	int i = -1;
	while (++i < m)
	{
		int j;
		cin >> j;
		broken.push_back(j);
	}

	return ;
}

int remote_con(void)
{
	int result;
	int min = find_min();
	result = abs(goal - 100);
	if (result > min)
		result = min;

	return (result);
}

int find_min(void)
{
	int channel = -1;
	int min_push = 1000000;

	while (++channel <= 1000000)
	{
		if (check_broken(channel) == 0)
			continue;

		int now_push = abs(channel - goal) + check_digit(channel);
		if (now_push < min_push)
			min_push = now_push;
	}

	return (min_push);
}

int check_broken(int channel)
{
	while (channel >= 0)
	{
		int units = channel % 10;
		int i = -1;
		while (++i < m)
		{
			if (units == broken[i])
				return (0);
		}
		channel /= 10;

		if (channel == 0)
			channel--;
	}

	return (1);
}

int check_digit(int channel)
{	
	int count = 0;

	if (channel == 0)
		return (1);

	while (channel > 0)
	{
		channel /= 10;
		count++;
	}

	return (count);
}