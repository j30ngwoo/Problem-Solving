#include <iostream>

using namespace std;

void input_data(void);
long long init(int, int, int);
void update(int, long long, int, int, int);
long long sum(int, int, int, int, int);

int n, m, k, count;
long long arr[1000001];
long long tree[4000004];

int main(void)
{
	input_data();
	init(1, 1, n);
	while (count-- > 0)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long difference = c - arr[b];
			arr[b] = c;
			update(b, difference, 1, 1, n);
		}
		else
			cout << sum(b, c, 1, 1, n) << '\n';
	}
	
	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int i = 0;
	while (++i <= n)
		cin >> arr[i];
	count = m + k;

	return ;
}

long long init(int node, int start, int end)
{
	if (start == end)
		return (tree[node] = arr[start]);

	int mid = (start + end) / 2;
	tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
	return (tree[node]);
}

void update(int target_index, long long difference, int node, int start, int end)
{
	if (target_index < start || end < target_index)
		return ;
	tree[node] += difference;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(target_index, difference, node * 2, start, mid);
		update(target_index, difference, node * 2 + 1, mid + 1, end);
	}	

	return ;
}

long long sum(int range_left, int range_right, int node, int tree_start, int tree_end)
{
	if (tree_end < range_left || range_right < tree_start)
    	return (0);

	if (range_left <= tree_start && tree_end <= range_right)
    	return (tree[node]);

	int mid = (tree_start + tree_end) / 2;
	return (sum(range_left, range_right, node * 2, tree_start, mid) + sum(range_left, range_right, node * 2 + 1, mid + 1, tree_end));
}