#include <iostream>

using namespace std;

long long lan[10000], first = 1, mid, last = 0;
int k, n;

void set_io(void);
void input_data(void);
void find(void);
int count_lan_num(void);

int main(void)
{
	set_io();
	input_data();
	find();

	return (0);
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return ;
}

void input_data(void)
{
	cin >> k >> n;

	int i = -1;
	while (++i < k)
	{
		cin >> lan[i];
		last = max(last, lan[i]);
	}

	return ;
}

void find(void)
{
	long long result = 0;

	while (first <= last)
	{
		mid = (first + last) / 2;
		int lan_num = count_lan_num();

		if (lan_num < n)
			last = mid - 1;
		else
		{
			first = mid + 1;
			result = max(result, mid);
		}
	}

	cout << result;

	return ;
}

int count_lan_num(void)
{
	int i = -1;
	int count = 0;

	while (++i < k)
		count += lan[i] / mid;

	return (count);
}