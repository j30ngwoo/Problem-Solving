#include <iostream>
using namespace std;

int n, c, count, arr[100];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= c; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % arr[j] == 0)
			{
				count++;
				break;
			}
		}
	}
	cout << count;
}