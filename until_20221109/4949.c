#include <stdio.h>

int	arr[1000000];

int	balance(char *str)
{
	int		i = -1;
	int		now = 0;
	char	stack[102];

	while(str[++i] != '.')
	{
		if (str[i] == '(')
		{
			stack[now] = '(';
			now++;
		}
		else if (str[i] == ')')
		{
			if (now >= 1 && stack[now - 1] == '(')
				now--;
			else
				return (0);
		}
		else if (str[i] == '[')
		{
			stack[now] = '[';
			now++;
		}
		else if (str[i] == ']')
		{
			if (now >= 1 && stack[now - 1] == '[')
				now--;
			else
				return (0);
		}
	}
	if (now == 0)
		return (1);
	else
		return (0);
}

void	output(void)
{
	int	i = -1;
	while (arr[++i] != -1)
	{
		if (arr[i] == 1)
			printf("yes\n");
		else 
			printf("no\n");
	}
	return ;
}

int	main(void)
{
	char	str[102];
	int		i = -1;

	gets(str);
	while(str[0] != '.')
	{
		arr[++i] = balance(str);
		gets(str);
	}
	arr[++i] = -1;
	output();
	return (0);
}
