#include <iostream>
using namespace std;

int time[257], map[500][500];
int n, m, b;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			map[i][j] = x; 
		}
	}

	for (int h = 0; h <= 256; h++)
	{
		int block_can_use = b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int diff = h - map[i][j];
				if (diff > 0)
				{
					time[h] += diff;
					block_can_use -= diff; 
				}
				else
				{
					time[h] += diff * (-2);
					block_can_use -= diff;
				}
			}
		}
		//cout << block_can_use << '\n';
		if (block_can_use < 0)
			time[h] = -1;
	}
	int min_time = -1;
	int min_height = -1;
	for (int h = 0; h <= 256 && time[h] != -1; h++)
	{
		if (time[h] <= min_time || min_time == -1)
		{
			min_time = time[h];
			min_height = h;
		}
	}
	cout << min_time << ' ' << min_height;
	
	return (0);
}