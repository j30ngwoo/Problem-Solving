#include <iostream>
#include <vector>
#include <algorithm>
#define INFINITY 1000000001


using namespace std;

class Cow {
	public:
		char direction;
		int x;
		int y;
		int index;
		int min_distance;
};

Cow cow_arr[51];
int n;

int measure_distance(Cow src, Cow dst) {
	if (src.direction == 'E' && dst.direction == 'N' && src.x <= dst.x && src.y >= dst.y && src.y - dst.y < dst.x - src.x && src.y - dst.y < dst.min_distance)
		return dst.x - src.x;
	if (src.direction == 'N' && dst.direction == 'E' && src.x >= dst.x && src.y <= dst.y && src.x - dst.x < dst.y - src.y && src.x - dst.x < dst.min_distance)
		return dst.y - src.y;
	if (src.direction == 'E' && dst.direction == 'E' && src.y == dst.y && src.x < dst.x)
		return dst.x - src.x;
	if (src.direction == 'N' && dst.direction == 'N' && src.x == dst.x && src.y < dst.y)
		return dst.y - src.y;
	return INFINITY;
}

bool compare_distance(Cow a, Cow b) {
	if (a.direction == 'E' && b.direction == 'N' && a.x <= b.x && a.y >= b.y && b.x - a.x > a.y - b.y)
		return false;
	if (a.direction == 'N' && b.direction == 'E' && a.x >= b.x && a.y <= b.y && b.y - a.y > a.x - b.x)
		return false;
	if (a.direction == 'E' && b.direction == 'E' && a.y == b.y && a.x > b.x)
		return false;
	if (a.direction == 'N' && b.direction == 'N' && a.x == b.x && a.y > b.y)
		return false;
	return true;
}

bool compare_index(Cow a, Cow b) {
	if (a.index < b.index)
		return true;
	else
		return false;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cow_arr[i].direction >> cow_arr[i].x >> cow_arr[i].y;
		cow_arr[i].index = i;
	}
	cout << compare_distance(cow_arr[2], cow_arr[5]) << '\n';
	
	sort(cow_arr, cow_arr + n, compare_distance);
	
	for (int i = 0; i < n; i++) printf("%d ", cow_arr[i].index);
	printf("\n");
	/*
	for (int current_index = 0; current_index < n; current_index++) {
		cow_arr[current_index].min_distance = INFINITY;
		for (int compare_index = 0; compare_index < current_index; compare_index++) {
			int new_distance = measure_distance(cow_arr[current_index], cow_arr[compare_index]);
			printf("%d to %d : %d\n", cow_arr[current_index].index, cow_arr[compare_index].index, new_distance);
			if (cow_arr[current_index].min_distance > new_distance)
				cow_arr[current_index].min_distance = new_distance;
		}
	}

	sort(cow_arr, cow_arr + n, compare_index);

	for (int i = 0; i < n; i++) {
		if (cow_arr[i].min_distance == INFINITY)
			cout << "Infinity\n";
		else
			cout << cow_arr[i].min_distance << "\n";
	}
	*/
	return (0);
}