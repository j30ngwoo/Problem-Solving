#include <iostream>
using namespace std;

int is_self[10001];

int main(void) {
	fill_n(is_self, 10001, 1);
	for (int i = 1; i < 10000; i++) {
		int now = i;
		int num = i;
		while (now > 0) {
			num += now % 10;
			now /= 10;
		}
		is_self[num] = 0;
	}

	for (int i = 1; i <= 10001; i++)
		if (is_self[i] == 1)
			cout << i << '\n';
}