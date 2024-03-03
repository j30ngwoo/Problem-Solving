#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int n, m, count = 0;
int sum[10001];

int main(void) {
	cin >> n >> m;
	FOR1(i, n) {
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num; 
	}
	FOR(i, n) {
		FOR1(j, n) {
			if (sum[j] - sum[i] == m)
				count++;
		}
	}
	cout << count;
}