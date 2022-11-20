#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	input_data(void);
int		count_meeting(void);
bool	compare(const pair<int, int> a, const pair<int, int> b);

vector<pair<int, int>>	rooms;
int	n;

int	main(void)
{
	input_data();
	sort(rooms.begin(), rooms.end(), compare);
	int result = count_meeting();
	cout << result;

	return (0);
}

void input_data(void)
{
	int start, end;
	cin >> n;
	
	int i = -1;
	while (++i < n)
	{
		cin >> start >> end;
		rooms.push_back(make_pair(start, end));
	}
}

bool compare(const pair<int, int> a, const pair<int, int> b)
{
	if (a.second == b.second)
		return (a.first < b. first);
	else
		return (a.second < b.second);
}

int	count_meeting(void)
{
	int len = rooms.size();
	int	now_endtime = 0, count = 0;
	int	i = -1;

	while (++i < len)
	{
		if (now_endtime <= rooms[i].first)
		{
			now_endtime = rooms[i].second;
			count++;
		}
	}
	return (count);
}