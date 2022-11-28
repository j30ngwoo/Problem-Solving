#include <iostream>
#include <vector>

using namespace std;

void	input_data(void);
int		remote_con(void);
int		find_min(void);

int goal;
vector<int> broken(0);

int main(void)
{
	input_data();
	cout << remote_con();

	return (0);
}

void input_data(void)
{
	int m;

	cin >> goal;
	cin >> m;
	while (m-- > 0)
	{
		int i;
		cin >> i;
		broken.push_back(i);
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

	}



}
