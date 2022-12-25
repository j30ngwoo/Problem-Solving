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

int find_parent(int x)
{
	if (parent[x] == x) 
		return x;
	parent[x] = find_parent(parent[x]);
	return (parent[x]);
}

void merge(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a > b)
		parent[a] = b;
    else
		parent[b] = a;

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
