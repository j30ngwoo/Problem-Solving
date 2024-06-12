#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int n, d, total_max;
int left_x, leftleft_x, left_y;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	for (int tci = 0; tci < tc; tci++) {
		vector<int> v[2];
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d;
			v[0].push_back(d);
		}
		for (int i = 0; i < n; i++) {
			cin >> d;
			v[1].push_back(d);
		}

		total_max = max({v[0][0], v[1][0]});
		for (int x = 1; x < n; x++) {
			left_x = x - 1 >= 0 ? x - 1 : 0;
			leftleft_x = x - 2 >= 0 ? x - 2 : 0;
			for (int y = 0; y < 2; y++) {
				left_y = !y;
				v[y][x] += max({v[left_y][left_x], v[left_y][leftleft_x]});
				total_max = max({total_max, v[y][x]});
			}
		}
		cout << total_max << '\n';
	}
	return (0);
}