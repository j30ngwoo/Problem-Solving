#include <stdio.h>

int graph[100][100];

void set_graph(int n, int node, int total)
{
	int i = -1;

	while(++i < total)
		graph[node][i] == n;
	return ;
}

int recursion_base(int node_to_find, int target, int total)
{
	int count = 0, flag = 1;
	recursion(node_to_find, target, total, &count, &flag);
	//printf("re : %d %d %d %d\n", node_to_find, target, total, count);
	return (count);
}

int	bacon_count(int	now_node, int total)
{
	int	count = 0, target = -1;
	while (++target < total)
		if (now_node != target)
			count += recursion_base(now_node, target, total);
	return (count);
}

int	min_bacon(int node)
{
	int min, i = 0;
	min = bacon_count(0, node);
	while(++i < node)
		if (min > bacon_count(i, node))
			min = bacon_count(i, node);
	return (min);
}

int main()
{
	int node, edge, i, x, y;
	scanf("%d %d", &node, &edge);
	i = -1;
	while(++i < edge)
	{
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	printf("%d", min_bacon(node));
	return (0);
}