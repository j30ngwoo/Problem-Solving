#include <iostream>
#include <string>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

string oper;
int m, s, n;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	FOR(i, m) {
		cin >> oper;
		if (oper == "add") {
			cin >> n;
			s |= 1 << n;
		} else if (oper == "remove") {
			cin >> n;
			s &= ~(1 << n);
		} else if (oper == "check") {
			cin >> n;
			cout << ((s & (1 << n)) ? 1 : 0) << '\n';
		} else if (oper == "toggle") {
			cin >> n;
			s ^= 1 << n;
		} else if (oper == "all") {
			s = 0b111111111111111111111;
		} else {
			s = 0;
		}
	}

	return (0);
}