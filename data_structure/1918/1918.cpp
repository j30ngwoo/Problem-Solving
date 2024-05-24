#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string s;
stack<char> stk;

int main(void) {
	cin >> s;	
	for (char c : s) {
		if (c == '+' || c == '-') {

		}
		else if (c == '*' || c == '/') {

		}
		else if (c == '(') {

		}
		else {
			cout << c;
		}
	}
	return (0);
}