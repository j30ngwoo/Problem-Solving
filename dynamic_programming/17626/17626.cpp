#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define MAX 10
using namespace std;	

int dp[50000];

int findMin(int n) {
	if (dp[n] != MAX)
		return (dp[n]);
	for (int i = 1; i * i < n; i++)
		dp[n] = min(dp[n], findMin(i * i) + findMin(n - i * i));
	return (dp[n]);
}

int main(void) {
	int n;
	fill_n(dp, 50001, MAX);
	for (int i = 1; i * i <= 50000; i++)
		dp[i * i] = 1;
	cin >> n;
	cout << findMin(n);
	return (0);
}