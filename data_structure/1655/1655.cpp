#include <iostream>
#include <queue>

using namespace std;

void say_middle(void);

int n;
priority_queue<int> left_q;
priority_queue<int, vector<int>, greater<int>> right_q;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    say_middle();

    return (0);
}

void say_middle(void)
{
    cin >> n;

    int i = -1;
    while (++i < n)
    {
        int input;
        cin >> input;
        if (left_q.empty())
        {
            left_q.push(input);
        }
        else if (right_q.empty())
        {
            if (left_q.top() <= input)
            {
                right_q.push(input);
            }
            else
            {
                right_q.push(left_q.top());
                left_q.pop();
                left_q.push(input);
            }
        }
        else
        {
            if (input < right_q.top())
                left_q.push(input);
            else
                right_q.push(input);
        }
        if (left_q.size() < right_q.size())
        {
            left_q.push(right_q.top());
            right_q.pop();
        }
        else if (left_q.size() > right_q.size() + 1)
		{
            right_q.push(left_q.top());
            left_q.pop();
		}
        cout << left_q.top() << '\n';
    }
}