#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

map<string, int> stringInt;
map<int, string> intString;
int n, m;
string s;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	FOR1(i, n) {
		cin >> s;
		stringInt.insert({s, i});
		intString.insert({i, s});
	}

	FOR1(i, m) {
		cin >> s;
		if ('0' < s[0] && s[0] <= '9')
			cout << intString[stoi(s)] << '\n';
		else
			cout << stringInt[s] << '\n';
	}


	return (0);
}
