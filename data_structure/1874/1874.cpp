#include <iostream>
#include <stack>

using namespace std;

int n, o, now_push = 1;
char output[200001];
stack<int> stk;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int i = 0;
	while (++i <= n)
	{
		int input;
		cin >> input;
		while (now_push <= input)
		{
			output[++o] = '+';
			stk.push(now_push);
			now_push++;
		}
		if (stk.top() > input)
		{
			cout << "NO" << '\n';
			return (0);
		}
		stk.pop();
		output[++o] = '-';
	}

	i = 0;
	while (++i <= n * 2)
		cout << output[i] << '\n';

	return (0);
}