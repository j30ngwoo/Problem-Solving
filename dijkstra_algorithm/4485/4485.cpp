#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void	input_data(void);
void	zelda(void);
void	check_four_directions(pair<int, int> now_node);
void	prt_arr(void);
void	prt_result(int c);

int		cave[126][126] = {0, };
int		graph[126][126];
int		n;
queue<pair<int, int>> q;
vector<int>	result;

int	main(void)
{
	int	i = 0, result_count = 0;
	while(1)
	{
		input_data();
		if (n == 0)
			break;
		fill(graph[0], graph[125], -1);
		zelda();
		result.push_back(graph[n - 1][n - 1]);
		result_count++;
	}
	prt_result(result_count);

	return (0);
}

void input_data(void)
{
	cin >> n;
	int	i = -1;
	while(++i < n)
	{
		int	j = -1;
		while(++j < n)
			cin >> cave[i][j];
	}
	
	return ;
}

void zelda(void)
{
	q.push(make_pair(0, 0));
	graph[0][0] = cave[0][0];

	while(!q.empty())
	{
		pair<int, int> now_node = q.front();
		q.pop();
		check_four_directions(now_node);
	}
	return ;
}

void check_four_directions(pair<int, int> now_node)
{
	int x = now_node.first;
	int y = now_node.second;

	//prt_arr();
	if (x > 0)
	{
		if(graph[x - 1][y] == -1 || graph[x - 1][y] > graph[x][y] + cave[x - 1][y])
		{
			q.push(make_pair(x - 1, y));
			graph[x - 1][y] = graph[x][y] + cave[x - 1][y];
		}
	}
	if (x < n - 1)
	{
		if(graph[x + 1][y] == -1 || graph[x + 1][y] > graph[x][y] + cave[x + 1][y])
		{
			q.push(make_pair(x + 1, y));
			graph[x + 1][y] = graph[x][y] + cave[x + 1][y];
		}
	}
	if (y > 0)
	{
		if(graph[x][y - 1] == -1 || graph[x][y - 1] > graph[x][y] + cave[x][y - 1])
		{
			q.push(make_pair(x, y - 1));
			graph[x][y - 1] = graph[x][y] + cave[x][y - 1];
		}
	}
	if (y < n - 1)
	{
		if(graph[x][y + 1] == -1 || graph[x][y + 1] > graph[x][y] + cave[x][y + 1])
		{
			q.push(make_pair(x, y + 1));
			graph[x][y + 1] = graph[x][y] + cave[x][y + 1];
		}
	}
	//cout << "now node: " << x << " " << y << endl;

	return ;
}

void prt_arr(void)
{
	int	i = -1;
	while (++i < n)
	{
		int j = -1;
		while (++j < n)
			cout << graph[i][j] << " ";
		cout << endl;
	}

	return ;
}

void prt_result(int c)
{
	int	i = -1;
	while (++i < c)
		cout << "Problem " << i + 1 << ": " << result[i] << endl;

	return ;
}