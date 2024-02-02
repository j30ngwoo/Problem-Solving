#include <iostream>
using namespace std;
int main(void) {
	int n, k, count = 0;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			count += 1;
			if (count == k) {
				cout << i;
				break;
			}
		}
	}
	if (count < k)
		cout << 0;
	return (0);
}