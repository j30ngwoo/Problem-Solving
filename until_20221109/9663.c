#include <stdio.h>

int	checkqueen(int n, int now, int arr[15])
{
	int x = -1;
	/*
	while (++x < n)
		printf("%d ", arr[x]);
	printf("\n");
	*/

	int	i = 0;
	while (++i <= now)
	{
		if (arr[now - i] == arr[now])
			return (0);
		if (arr[now] - i >= 0 && arr[now - i] == arr[now] - i)
			return (0);
		if (arr[now] + i < n && arr[now - i] == arr[now] + i)
			return (0);
	}
	return (1);
}

void recursion(int n, int now, int arr[15], int *result)
{
	int	i = -1;
	int	is_checked;
	while (++i < n)
	{
		arr[now] = i;
		is_checked = checkqueen(n, now, arr);
		//printf("%d\n", is_checked);

		if (is_checked && now == n - 1)
			(*result)++;
		if (is_checked && now < n - 1)
			recursion(n, now + 1, arr, result);
	}
	return ;
}

int	n_queen(int n)
{
	int arr[15] = {0};
	int result = 0, now = 0;

	recursion(n, now, arr, &result);
	return (result);
}

int	main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", n_queen(n));
	return (0);
}