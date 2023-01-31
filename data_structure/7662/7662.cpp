#include <iostream>
#include <queue>
using namespace std;

void dual(void);
int is_valid[1000001];
priority_queue<pair<int, int>> max_heap;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		fill(is_valid, is_valid + 1000001, 1);
		dual();
		while (!max_heap.empty())
			max_heap.pop();
		while (!min_heap.empty())
			min_heap.pop();
	}

	return (0);
}

void dual(void)
{
	int k, index = 0;
	cin >> k;
	
	while (k--)
	{
		char calculation;
		int n;
		cin >> calculation >> n;
		if (calculation == 'I')
		{
			max_heap.push({n, index});
			min_heap.push({n, index});
			index++;
		}
		else if (n == 1)
		{
			while (!max_heap.empty() && !is_valid[max_heap.top().second])
				max_heap.pop();
			if (!max_heap.empty())
			{
				is_valid[max_heap.top().second] = 0;
				max_heap.pop();
			}
		}
		else if (n == -1)
		{
			while (!min_heap.empty() && !is_valid[min_heap.top().second] )
				min_heap.pop();
			if (!min_heap.empty())
			{
				is_valid[min_heap.top().second] = 0;
				min_heap.pop();
			}
		}
	}

	while (!max_heap.empty() && !is_valid[max_heap.top().second])
		max_heap.pop();
	while (!min_heap.empty() && !is_valid[min_heap.top().second])
		min_heap.pop();
	
	if (max_heap.empty())
		cout << "EMPTY" << '\n';
	else
		cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';

	return ;
}