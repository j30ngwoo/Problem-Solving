#include <iostream>
#include <vector>
#include <map>
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

map<string, int> m;

int tc, n, result;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	FOR(t, tc) {
		m.clear();
		cin >> n;
		FOR(i, n) {
			string temp, s;
			cin >> temp >> s;
			if (m.find(s) != m.end())
				m[s] += 1;
			else
				m[s] = 1;
		}
		result = 1;
		for (auto e : m)
			result *= e.second + 1;
		cout << result - 1 << '\n';
	}

	return (0);
}