#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

void	set_io(void);
void	input_data(void);
void	union_find(void);
int		find_parent(int child);
void	merge(int a, int b);
void	is_in_union(int a, int b);


int main(void)
{
	set_io();
	input_data();
	union_find();

	return (0);
}

void set_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	return ;
}

void input_data(void)
{
	cin >> n >> m;
	
	int i = -1;
	while (++i <= n)
		parent[i] = i;

	return ;
}

void union_find(void)
{
	int calculation, a, b;

	int i = -1;
	while (++i < m)
	{
		cin >> calculation >> a >> b;
		if (calculation == 0)
			merge(a, b);
		else if (calculation == 1)
			is_in_union(a, b);
	}

	return ;
}

int find_parent(int child)
{
	if (parent[child] != child)
		find_parent(parent[child]);
	return (child);
}

void merge(int a, int b)
{
	int	a_parent = find_parent(a);
	int	b_parent = find_parent(b);

	if (a_parent != b_parent)
		parent[a] = b_parent;

	return ;
}

void is_in_union(int a, int b)
{
	if (find_parent(a) == find_parent(b))
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	
	return ;
}
