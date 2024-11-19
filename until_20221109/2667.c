#include <stdio.h>
#include <stdlib.h>
#define N 500

int	arr[25][25];

int	checkarr(int i, int j, int n)
{
	if(i < 0 || i >= n || j < 0 || j >= n)
		return (0);
	else
		return (1);
}

void	recursion(int i, int j, int now, int n)
{
	arr[i][j] = now;
	//printf("%d, %d, %d\n", i, j, now);
	int x[4] = {0, 1, 0, -1};
	int y[4] = {1, 0, -1, 0};
	int four = -1;

	while(++four < 4)
		if(checkarr(i + x[four], j + y[four], n) && arr[i + x[four]][j + y[four]] == 1)
			recursion(i + x[four], j + y[four], now, n);	
}

void	changenum(int n)
{
	int	i = -1;
	int	j = -1;
	int	now = 2;

	while(++i < n)
	{
		j = -1;
		while(++j < n)
		{
			if(arr[i][j] == 1)
			{
				recursion(i, j, now, n);
				now++;
			}
		}
	}
}

int	*countnum(int n)
{
	int	i = -1;
	int	j = -1;
	static int	result[N] = {0};

	while(++i < n)
	{
		j = -1;
		while(++j < n)
		{
			if(arr[i][j] >= 2)
				result[arr[i][j] - 2]++;
		}
	}
	return (result);
}

int compare(const void *a , const void *b) 
{ 
	if( *(int*)a > *(int*)b )
		return 1;
	else if( *(int*)a < *(int*)b )
		return -1;
	else
		return 0;
} 

int	main()
{
	int	n, now = 2, i = -1, j = -1, cnt = 0;

	scanf("%d", &n);
	while(++i < n)
	{
		j = -1;
		while(++j < n)
			scanf("%1d", &arr[i][j]);
	}
	i = -1;
	changenum(n);
	int *result = countnum(n);
	while(result[++i] > 0);
	qsort(result, i, sizeof(int), compare);
	j = -1;
	printf("%d\n", i);
	while(++j < i)
		printf("%d\n", result[j]);
	return (0);
}