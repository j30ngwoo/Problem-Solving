#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void input_data(void);
void find_max(void);

struct cmp {
bool operator()(pair<int, int>&a, pair<int, int>&b) {
		return (a.second < b.second);
	}
};

int n, m, v, k, c;
long long result;
int bag[300000];
pair<int, int> gem[300000];
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> gem_q;

int main(void)
{
	input_data();
	find_max();

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int i = -1;
	while (++i < n)
		cin >> gem[i].first >> gem[i].second;
	
	i = -1;
	while (++i < k)
		cin >> bag[i];
	
	sort(gem, gem + n);
	sort(bag, bag + k);

	return ;
}

void find_max(void)
{
	int bag_idx = -1, gem_idx = 0;
	while (++bag_idx < k)
	{
		while (bag[bag_idx] >= gem[gem_idx].first && gem_idx < n)
		{
			gem_q.push(gem[gem_idx]);
			gem_idx++;
		}
		if (!gem_q.empty())
		{
			result += gem_q.top().second;
			gem_q.pop();
		}
	}

	cout << result << '\n';

	return;
}