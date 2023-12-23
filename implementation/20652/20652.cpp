#include <iostream>
#include <vector>
#include <algorithm>
#define INFINITY 1000000001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

class Cow {
	public:
		char direction;
		int x;
		int y;
};

class Intersect {
	public:
		Cow stop_cow;
		Cow continue_cow;
		int time;
		int x;
		int y;
};

vector<Cow> cows;
vector<Intersect> intersects;
int n;

int main(void) {
	cin >> n;
	FOR(i, n) {
		char direction;
		int x, y;
		cin >> direction >> x >> y;
		cows.push_back({direction, x, y});
	}
	
	FOR(a, n) {
		FOR(b, n) {
			if (cows[a].direction == 'E' && cows[b].direction == 'N' && cows[a].x < cows[b].x && cows[a].y > cows[b].y) {
				if (cows[b].x - cows[a].x < cows[a].y - cows[b].y)
					intersects.push_back({cows[b], cows[a], cows[]});

				else if (cows[])
			}
		}
	}


	return (0);
}