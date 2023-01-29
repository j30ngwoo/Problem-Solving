#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int people[1000];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int i = -1;
	while (++i < n)
		cin >> people[i];

	sort(people, people + n, greater<>());

	i = -1;
	while (++i < n)
		sum += people[i] * (i + 1);
	cout << sum;

	return (0);
}