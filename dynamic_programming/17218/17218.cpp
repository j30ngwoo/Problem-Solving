#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
string table[41][41];

int main(void) {
	cin >> s1 >> s2;
	s1.insert(0, "X");
	s2.insert(0, "X");

	for (int y = 1; y < s1.length(); y++) {
		for (int x = 1; x < s2.length(); x++) {
			if (s1[y] == s2[x])
				table[y][x] = table[y - 1][x - 1] + s1[y];
			else if (table[y - 1][x].length() > table[y][x - 1].length())
				table[y][x] = table[y - 1][x];
			else
				table[y][x] = table[y][x - 1];
		}
	}
	cout << table[s1.length() - 1][s2.length() - 1];

	return (0);
}