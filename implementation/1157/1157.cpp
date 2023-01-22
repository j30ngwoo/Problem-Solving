#include <iostream>

using namespace std;

char input[1000001];
int count[26];

int main(void)
{
	cin >> input;

	int i = -1;
	while (input[++i])
	{
		if (input[i] >= 'a')
			count[input[i] - 'a']++;
		else
			count[input[i] - 'A']++;
	}

	int result = 0;
	i = 0;
	while (++i < 26)
		if (count[result] < count[i])
			result = i;

	i = -1;
	while (++i < 26)
	{
		if (count[result] == count[i] && result != i)
		{
			cout << '?' << '\n';
			return (0);
		}
	}

	char a = result + 'A';
	cout << a << '\n';

	return (0);
}