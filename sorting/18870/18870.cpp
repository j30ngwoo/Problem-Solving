#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> coordinates;
vector<int> sorted;
int n;

void set_io(void);
void input_data(void);
void compress(void);

int main(void)
{
	set_io();
	input_data();
	compress();

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
	cin >> n;

	int i = -1;
	while (++i < n)
	{
		int input;
		cin >> input;
		coordinates.push_back(input);
		sorted.push_back(input);
	}

	return ;
}

void compress(void)
{
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	int sorted_length = sorted.size();

	int i = -1;
	while (++i < n)
		cout << lower_bound(sorted.begin(), sorted.end(), coordinates[i]) - sorted.begin() << ' ';

	return ;
}