#include <iostream>
#include <algorithm>
#define ll long long
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(void) {
	ll n, max = 0, maxTuition = 0;
	cin >> n;
	ll arr[n];
	FOR(i, n) cin >> arr[i];
	sort(arr, arr + n);
	FOR(i, n) {
		ll nowTuition = arr[i] * (n - i);
		if (max < nowTuition) {
			max = nowTuition;
			maxTuition = arr[i];
		}	
	}
	cout << max << ' ' << maxTuition;
	return (0);
}