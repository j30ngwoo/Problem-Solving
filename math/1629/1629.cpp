#include <iostream>
typedef long long ll;
using namespace std;

ll a, b, c;

ll recursion(int exponent)
{
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (a % c);
	ll half_result = recursion(exponent / 2) % c;
	ll result = half_result * half_result % c;
	if (exponent % 2 == 1)
		return (result * a % c);
	else
		return (result);
}

int main(void)
{
	cin >> a >> b >> c;
	cout << recursion(b);
	
	return (0);
}