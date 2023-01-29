#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int last_num, k, sum;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	while (k--)
	{
		int input;
		cin >> input;
		if (input)
			stk.push(input);
		else
			stk.pop();
	}

	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}
	cout << sum;

	return (0);
}