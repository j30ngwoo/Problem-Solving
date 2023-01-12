#include <iostream>

using namespace std;

void input_data(void);
long long init(int, int, int);

int n, m, k;
int arr[1000000];
long long tree[4000000];

int main(void)
{
	input_data();
	init

	return (0);
}

void input_data(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int i = -1;
	while (++i < n)
		cin >> arr[i];

	return ;
}

long long init(int node, int start, int end)
{
	if (start == end)
		return (arr[start]);

	int mid = (start + end) / 2;
	tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
	return (tree[node]);
}