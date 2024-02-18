#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;

ll arr[101] = {0, 1, 1};
int tc, n;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 3; i <= 100; i++)
		arr[i] = arr[i - 2] + arr[i - 3];
	cin >> tc;
	FOR(t, tc) {
		cin >> n;
		cout << arr[n] << '\n';
	}	

	return (0);
}