#include <iostream>
#include <stack>
#include <deque>

using namespace std;

void keylogger(void);

int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int i = -1;
    while (++i < n)
        keylogger();

    return (0);
}

void keylogger(void)
{
    string input;
    deque<char> left_stk;
    stack<char> right_stk;

    cin >> input;

    int i = -1;
    while (++i < input.size())
    {
        if (input[i] == '<' && !left_stk.empty())
        {
            right_stk.push(left_stk.back());
            left_stk.pop_back();
        }
        else if (input[i] == '>' && !right_stk.empty())
        {
            left_stk.push_back(right_stk.top());
            right_stk.pop();
        }
        else if (input[i] == '-' && !left_stk.empty())
            left_stk.pop_back();
        else if (input[i] != '<' && input[i] != '>' && input[i] != '-')
            left_stk.push_back(input[i]);
    }

    while (!left_stk.empty())
    {
        cout << left_stk.front();
        left_stk.pop_front();
    }
    while (!right_stk.empty())
    {
        cout << right_stk.top();
        right_stk.pop();
    }
    cout << '\n';

    return ;
}