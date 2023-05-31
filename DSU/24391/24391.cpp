#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

vector<int> parent;
int n, m;

int find(int x)
{
	if (parent[x] == x)
		return (x);
	return (parent[x] = find(x));
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	parent[a] = b;
}

void init(void)
{
	int i;

	i = 0;
	while (++i <= n)
		parent[i] = i;
}

int main(void)
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	parent.resize(n + 1);
	init();
	while (m-- > 0)
	{
		int i, j;
		cin >> i >> j;
		merge(i, j);
		write(1, "@\n", 1);
	}
	int count = 0, now_class, last_class = 0;
	while (n-- > 0)
	{
		cout << "n=" << n << '\n';
		cin >> now_class;
		if (last_class != 0 && find(now_class) == find(last_class))
			count++;
		last_class = now_class;
	}

	cout << count;
	return (0);
}