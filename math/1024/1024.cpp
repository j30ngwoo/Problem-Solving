#include <iostream>
using namespace std;

int n, l;

void print_arr(int start, int length) {
	for (int i = start; i < start + length; i++) {
		cout << i << ' ';
	}
}

int main(void) {
	cin >> n >> l;

	for (int length = l; length <= 100; length++) {
		if (n % length == 0 && (n / (n / length)) % 2 == 1 && n / length - length / 2 >= 0) {
			print_arr(n / length - length / 2, length);
			return (0);
		}
		if (length % 2 == 0 && n % length == length / 2 && n % ((n / length) * 2 + 1)== 0 && n / length - length / 2 + 1 >= 0)  {
			print_arr(n / length - length / 2 + 1, length);
			return (0);
		}
	}
	cout << -1;
	return (0);
}