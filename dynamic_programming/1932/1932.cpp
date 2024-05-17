#include <iostream>
#include <vector>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, result;
int input[500][500];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	FOR (i, n)
		FOR (j, i + 1)
			cin >> input[i][j];

	for (int layer = 1; layer < n; layer++) {
		for (int index = 0; index <= layer; index++) {
			if (index == 0)
				input[layer][index] += input[layer - 1][index];
			else if (index == layer)
				input[layer][index] += input[layer - 1][index - 1];
			else
				input[layer][index] += max(input[layer - 1][index - 1], input[layer - 1][index]);
			//cout << input[layer][index] << ' ';
		}
		//cout << '\n';
	}

	for (int i = 0; i < n; i++)
		result = max(input[n - 1][i], result);
	cout << result;
	return (0);
}