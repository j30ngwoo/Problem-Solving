#include <iostream>

using namespace std;

int main(void)
{
	int n, i = -1, sum = 0;
	cin >> n; 
	while (++i < n)
	{
		char input;
		cin >> input;
		sum += input - '0';
	}
	cout << sum;
	return (0);
}