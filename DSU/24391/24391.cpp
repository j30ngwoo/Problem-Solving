#include <iostream>
#include <unistd.h>
using namespace std;
int parent[100001], n, m;

int find(int x)
{
	if (parent[x] == x)
		return (x);
	parent[x] = find(parent[x]);
	return (parent[x]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	parent[a] = b;
}

int	prt_arr(void)
{
	int i = 0;
	while (++i <= n)
		cout << parent[i] << " ";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int x = -1;
	while (++x <= n)
	{
		parent[x] = x;
	}
	x = 0;
	while (x++ < m)
	{
		int i, j;
		cin >> i >> j;
		merge(i, j);
	}
	int count = 0, now_class, last_class = 0;
	x = 0;
	while (x++ < n)
	{
		cin >> now_class;
		cout << "class: " << now_class << ' ' << last_class << '\n';
		cout << "find : " << find(now_class) << ' ' << find(last_class) << '\n';
		if (last_class != 0 && find(now_class) == find(last_class))
			count++;
		last_class = now_class;
	}
	
	cout << count;
	return (0);
}