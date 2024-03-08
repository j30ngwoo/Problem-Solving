#include <iostream>
using namespace std;

int main(void) {
	int e, s, m, i = 1;
	cin >> e >> s >> m;
	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;
	while (!(i % 15 == e && i % 28 == s && i % 19 == m))
		i++;
	cout << i;

	return (0);
}

