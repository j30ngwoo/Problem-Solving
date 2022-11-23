#include <iostream>
#include <queue>

using namespace std;

void	input_data(void);
int		sort_card(void);

priority_queue<int, vector<int>, greater<int>> p_queue;
int n;

int main(void)
{
	input_data();
	cout << sort_card();

	return (0);
}

void input_data(void)
{
	cin >> n;

	int i = -1;
	while (++i < n)
	{
		int card;
		cin >> card;
		p_queue.push(card);
	}
	return ;
}

int sort_card(void)
{
	if (n == 1)
		return (0);
	
	int output = 0;
	while(p_queue.size() > 1)
	{
		int tmp = p_queue.top();
		p_queue.pop();
		tmp += p_queue.top();
		p_queue.pop();
		output += tmp;
		p_queue.push(tmp);
	}

	return (output);
}