#include <stdio.h>
#include <stdlib.h>

#define N 2000

int compare(const void *a , const void *b) 
{ 
	if( *(int*)a > *(int*)b )
		return 1;
	else if( *(int*)a < *(int*)b )
		return -1;
	else
		return 0;
}


int	is_good(int n, int val, int idx, int *arr)
{
	int x = 0, y = n - 1, sum;
	while (1)
	{
		if (x == y)
			return (0);
		else if (x != idx && y != idx)
		{
			sum = arr[x] + arr[y];
			if (sum > val)
				y--;
			else if (sum < val)
				x++;
			else
				return (1);
		}
		else if (x == idx)
			x++;
		else if (y == idx)
			y--;
	}
}

int good_count(int n, int *arr)
{
	int	cnt = 0, i = -1;

	while (++i < n)
		if (is_good(n, arr[i], i, arr))
			cnt++;
	return (cnt);
}

int	main()
{
	int arr[N] = {0};
	int n, result = 0, i, std, cnt;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	cnt = good_count(n, arr);
	printf("%d", cnt);

	return (0);
}