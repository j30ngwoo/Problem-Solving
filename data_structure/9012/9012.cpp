#include <iostream>
#include <stack>

using namespace std;

void check_vps(void);

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (--n >= 0)
		check_vps();

	return (0);
}

void check_vps(void)
{
	stack<int> stk;
	string str;

	cin >> str;
	int i = -1;
	while (++i < str.length())
	{
		if (str[i] == '(')
			stk.push(1);
		else if (str[i] == ')')
		{
			if (!stk.empty())
				stk.pop();
			else
			{
				cout << "NO" << '\n';
				return ;
			}
		}
	}
	if (stk.empty())
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return ;
}