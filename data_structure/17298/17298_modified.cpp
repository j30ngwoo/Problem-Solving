#include <iostream>
#include <stack>

using namespace std;

void input_data(void);
void right_biggest(void);
void prt_result(void);

int input[1000000];
int output[1000000];
int n;
stack<int> stk;

int main(void)
{
	input_data();
	right_biggest();
	prt_result();

	return (0);
}

void input_data(void)
{
	cin >> n;

	int i = -1;

	while(++i < n)
		cin >> input[i];

	return ;
}

void right_biggest(void)
{
	int i = n;

	while (--i >= 0)
	{
		while (!stk.empty() && stk.top() <= input[i])
			stk.pop();

		if (stk.empty())
			output[i] = -1;
		else
			output[i] = stk.top();

		stk.push(input[i]);
	}

	return ;
}

void prt_result(void)
{
	int i = -1;

	while(++i < n)
		cout << output[i] << " ";

	return ;
}