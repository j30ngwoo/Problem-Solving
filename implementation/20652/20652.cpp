#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cow {
	public:
		char direction;
		int x;
		int y;
};

Cow cow_arr[51];
int n;

bool compare(Cow a, Cow b) {
	if (a.direction == 'E' && a.x < b.x) {
		
	}
	return (1);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cow_arr[i].direction >> cow_arr[i].x >> cow_arr[i].y;
	
	sort(cow_arr, cow_arr + n, compare);

	return (0);
}