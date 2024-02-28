#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int count = 0;
	int n, i = 0;
	cin >> n;
	while (count < n) {
		if (to_string(i).find("666") != string::npos)
			count++;
		i++;
	}
	cout << i - 1;
}
