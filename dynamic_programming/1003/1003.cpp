#include <iostream>

using namespace std;

int dp[41][2];

int main(void)
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set();
	int n;
	cin >> n;
	while (n--)
	{
		int input;
		cin >> input;
		cout << arr[0][input] << ' ' << arr[1][input] << '\n';
	}

	return (0);
}

void set(void)
{
	arr[0][0] = 1;
	arr[1][1] = 1;

	int i = 1;
	while (++i < 41)
	{
		arr[0][i] = arr[0][i - 1] + arr[0][i - 2];
		arr[1][i] = arr[1][i - 1] + arr[1][i - 2];
	}

	return ;
}