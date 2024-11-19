#include <stdio.h>

int original_graph[100][100] = {0};
int graph[100][100];

int recursion_base(int now_node, int target, int total)
{
	int count = 0, i = -1;
	while(1)
	{
		while(++i < total)
		{
			if()
		}
		++count
	}

}

int	bacon_count(int	now_node, int total)
{
	int	count = 0, target = -1;
	while (++target < total)
		if (now_node != target)
			count += recursion_base(now_node, target, total);
	return (count);
}

int	min_bacon(node)
{
	int count, i = 0;
	count = bacon_count(0, node);
	while(++i < node)
		if (count > bacon_count(i, node))
			count = bacon_count(i, node);
	return (count);
}

int main()
{
	int node, edge, i, x, y;
	scanf("%d %d", &node, &edge);
	i = -1;
	while(++i < edge)
	{
		scanf("%d %d", &x, &y);
		original_graph[x][y] = 1;
		original_graph[y][x] = 1;
	}
	graph = original_graph; 
	printf("%d", min_bacon(node));
	return (0);
}