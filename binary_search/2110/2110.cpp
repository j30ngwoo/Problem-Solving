#include <iostream>
#include <algorithm>

using namespace std;

void input_data(void);
void find_max(void);

int n, c, result;
int house[200000];

int main(void)
{
	input_data();
	find_max();

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	int i = -1;
	while (++i < n)
		cin >> house[i];

	sort(house, house + n);

	return ;
}

void find_max(void)
{
	int first = 0, last = house[n - 1] - house[0];

	while (first <= last)
	{
		int mid = (first + last) / 2;
		int count = 1, last_coordinate = house[0];
		int i = 0;

		while (++i < n && count < c)
		{
			if (house[i] - last_coordinate >= mid)
			{
				count++;
				last_coordinate = house[i];
			}
		}

		if (count == c)
		{
			result = mid;
			first = mid + 1;
		}
		else
			last = mid - 1;
	}

	cout << result << '\n';

	return ;
}