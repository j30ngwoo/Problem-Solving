#include <iostream>

using namespace std;

long long n, m, sum, result;
long long remainder_count[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int i = -1;
	while (++i < n)
	{
		long long input;
		cin >> input;
		sum += input;
		remainder_count[sum % m]++;
	}
	remainder_count[0]++;

	i = -1;
	while (++i < 1001)
		result += remainder_count[i] * (remainder_count[i] - 1) / 2;

	cout << result << '\n';

	return (0);
}
