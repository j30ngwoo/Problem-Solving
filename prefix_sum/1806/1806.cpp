#include <iostream>

using namespace std;

void input_data(void);
void prefix_sum(void);

int arr[100001];
int accumulate[100001];
int n, s;

int main(void)
{
	input_data();
	prefix_sum();

	return (0);
}


void input_data(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	arr[0] = accumulate[0] = 0;
	cin >> n >> s;

	int i = 0;
	while (++i <= n)
		cin >> arr[i];
	i = 0;
	while (++i <= n)
		accumulate[i] = arr[i] + accumulate[i - 1];

	return ;
}

void prefix_sum(void)
{
	int result = 200000;
	int first = 1, second = 1;
	
	while (first <= second && second <= n)
	{
		if ((accumulate[second] - accumulate[first - 1]) >= s)
		{
			result = min(result, second - first + 1);
			first++;
		}
		else
			second++;
	}

	if (result == 200000)
		cout << 0 << '\n';
	else
		cout << result << '\n';

	return;
}