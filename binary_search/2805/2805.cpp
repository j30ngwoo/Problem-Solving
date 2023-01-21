#include <iostream>

using namespace std;

void input_data(void);
void find_max(void);
long long now_sum(int cut);

int n, m, result;
int trees[1000000];

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

	cin >> n >> m;
	
	int i = -1;
	while (++i < n)
		cin >> trees[i];

	return ;
}

void find_max(void)
{
	int first = 0, last = 1000000000;

	while (first <= last)
	{
		int mid = (first + last) / 2;
		long long sum = now_sum(mid);

		if (sum >= m)
		{
			result = max(result, mid);
			first = mid + 1;
		}
		else
			last = mid - 1;
	}

	cout << result << '\n';

	return ;
}

long long now_sum(int cut)
{
	long long sum = 0;

	int i = -1;
	while (++i < n)
		if (trees[i] - cut > 0)
			sum += trees[i] - cut;

	return (sum);
}