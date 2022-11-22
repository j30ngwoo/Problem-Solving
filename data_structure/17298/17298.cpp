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
		if (!stk.empty())
		{
			while (1)
			{
				if (stk.empty())
				{
					output[i] = -1;
					stk.push(input[i]);
					break;
				}
				else
				{ 
					if (stk.top() > input[i])
					{
						output[i] = stk.top();
						stk.push(input[i]);
						break;
					}
					else
						stk.pop();
				}
			}
		}
		else 
		{
			output[i] = -1;
			stk.push(input[i]);
		}
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