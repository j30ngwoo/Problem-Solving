#include <iostream>

using namespace std;

string str, frula, result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	explosion();

	return (0);
}

void explosion(void)
{
	cin >> str;
	cin >> frula;

	int i = -1;
	int result_index = -1;
	
	while (++i < str.size())
	{
		int frula_index = frula.size() + 1;
		result[++result_index] = str[i];
		while (flula[--frula_index] == result[result_index] && result_index >= 0)
		{
			
		}
	}

	cout << result;

	return ;
}