#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string input;
	int result = 0, neg_flag = 0, now_int = 0;
	
	cin >> input;

	int i = -1;
	while (input[++i])
	{
		
		if (input[i] >= '0')
		{
			now_int *= 10;
			now_int += input[i] - '0';
		}
		else
		{
			if (neg_flag == 0)
				result += now_int;
			else
				result -= now_int;
			if (input[i] == '-')
				neg_flag = 1;
			now_int = 0;
		}
	}
	if (neg_flag == 0)
		result += now_int;
	else
		result -= now_int;

	cout << result;

	return (0);
}