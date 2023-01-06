#include <iostream>
#include <string>
#include <deque>

using namespace std;

string functions;
string input_arr;
int arr_length;
deque<int> int_deque;

void set_io(void);
void input_data(void);
void ac(void);
void prt_result(int is_reversed);

int main(void)
{
	set_io();
	int testcase;
	cin >> testcase;

	while (testcase-- > 0)
	{
		input_data();
		ac();
	}

	return (0);
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return ;
}

void input_data(void)
{
	cin >> functions;
	cin >> arr_length;
	cin >> input_arr;

	if (arr_length == 0)
		return ;

	int i = 0;
	while (input_arr[i] != ']')
	{
		int now_int = 0;
		while (input_arr[++i] >= '0' && input_arr[i] <= '9')
		{
			now_int *= 10;
			now_int += input_arr[i] - '0';
		}
		int_deque.push_back(now_int);
	}

	return ;
}

void ac(void)
{
	int function_length = functions.length();
	int i = -1;
	int is_reversed = 0;

	while (++i < function_length)
	{
		if (functions[i] == 'R')
			is_reversed = is_reversed ? 0 : 1;
		else
		{
			if (int_deque.empty())
			{
				cout << "error" << '\n';
				return ;
			}
			is_reversed ? int_deque.pop_back() : int_deque.pop_front();
			arr_length--;
		}
	}
	prt_result(is_reversed);

	return ;
}

void prt_result(int is_reversed)
{
	cout << '[';

	if (is_reversed == 0)
	{
		while (!int_deque.empty())
		{
			cout << int_deque.front();
			if (arr_length > 1)
			{
				cout << ',';
				arr_length--;
			}
			int_deque.pop_front();
		}
	}
	else
	{
		while (!int_deque.empty())
		{
			cout << int_deque.back();
			if (arr_length > 1)
			{
				cout << ',';
				arr_length--;
			}
			int_deque.pop_back();
		}
	}

	cout << ']' << '\n';
	
	return ;
}