#include <iostream>
#include <map>
#include <string>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

int n, m;
map<string, string> dict;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	FOR(i, n) {
		string a, pw;
		cin >> a >> pw;
		dict.insert({a, pw});
	}

	FOR(i, m) {
		string a;
		cin >> a;
		cout << dict[a] << '\n';
	}

	return (0);
}