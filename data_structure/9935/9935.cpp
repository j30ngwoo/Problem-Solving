#include <iostream>
using namespace std;

void explosion(void);
string str, frula, result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	str.reserve(1000001);
	frula.reserve(40);
	result.reserve(1000001);

	explosion();

	return (0);
}

void explosion(void)
{
	cin >> str;
	cin >> frula;

	int i = -1;
	int result_index = -1;
	int result_size = str.size();
	int last_result_index;

	while (++i < str.size())
	{
		int frula_index = frula.size() - 1;
		result[++result_index] = str[i];
		last_result_index = result_index;
		while (last_result_index >= 0 && frula_index >= 0)
		{
			if (result[last_result_index] == frula[frula_index])
			{
				frula_index--;
				last_result_index--;
			}
			else
				break;
		}
		if (frula_index == -1)
		{
			result_size -= frula.size();
			result_index = last_result_index;
		}
	}

	if (result_size == 0)
		cout << "FRULA";
	else
	{
		i = -1;
		while (++i < result_size)
			cout << result[i];
	}

	return ;
}