#include <iostream>
using namespace std;

int main(void) {
	int n, count = 0;
	cin >> n;
	for (int x = 1; x <= n; x++) {
		int i = x;
		while (i > 0) {
			if (i % 10 == 3 || i % 10 == 6 || i % 10 == 9)
				count += 1;
			i /= 10;
		}
	}
	cout << count;
	return (0);
}