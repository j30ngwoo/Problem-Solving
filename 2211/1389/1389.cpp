#include <iostream>
#include <queue>
#define MAX 

using namespace std;

void	input_data(void);
void	bacon(void);
void	print_graph(vector<vector<int>> &graph);

vector<vector<int>>	graph;
vector<bool>		is_visited;

int main(void)
{
	
	queue<int>			q;

	input_data();
	print_graph(graph);
	//bacon();
	return (0);
}

void input_data(void)
{
	int	v, e;
	cin >> v >> e;

	graph.assign(v + 1, vector<int>(0));
	is_visited.assign(v + 1, 0);

	int i = -1;
	while (++i < e)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	return ;
}

void print_graph(vector<vector<int>> *graph)
{
	int i = 0;
	while (++i < (*graph).size())
	{
		int j = -1;
		cout << i << ": ";
		while (++j < (*graph)[i].size())
			cout << (*graph)[i][j] << " ";
		cout << endl;
	}
}

