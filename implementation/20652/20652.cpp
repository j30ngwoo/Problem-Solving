#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

struct Cow {
	int x;
	int y;
	int id;
};

struct Stop {
	int x;
	int y;
};

bool ascendingX(Cow a, Cow b) {
	return a.x < b.x;
}

bool ascendingY(Cow a, Cow b) {
	return a.y < b.y;
}

vector<Cow> eastCows;
vector<Cow> northCows;
vector<Stop> stops(50, {0, 0});
vector<int> result(50, INF);

int main(void) {
	int n;
	cin >> n;
	FOR(i, n) {
		char direction;
		int x, y;
		cin >> direction >> x >> y;
		if (direction == 'E') eastCows.push_back({x, y, i});
		if (direction == 'N') northCows.push_back({x, y, i});
	}

	sort(northCows.begin(), northCows.end(), ascendingX); // northCow는 x좌표 오름차순
	sort(eastCows.begin(), eastCows.end(), ascendingY); // eastCow는 y좌표 오름차순
	
	// 각 northCow에 대한 eastCow의 충돌 확인
	for (auto northCow: northCows) {
		for (auto eastCow: eastCows) {
			if (eastCow.x < northCow.x && northCow.y < eastCow.y) {
				int eastDist = northCow.x - eastCow.x;
				int northDist = eastCow.y - northCow.y;
				if (northDist < eastDist && stops[eastCow.id].x == 0) { // eastCow가 정지 && 이전의 northCow에서 정지한 적 없음
					stops[eastCow.id] = ({northCow.y, eastCow.x});         // eastCow의 정지 위치 표시
				} 
				if (eastDist < northDist && stops[eastCow.id].x == 0) { // northCow가 정지 && 겹친 eastCow는 이전에 정지한 적 없음
					stops[northCow.id] = ({northCow.y, eastCow.x});      // northCow의 정지 위치 표시. 정지하였으므로 다음 northCow로 넘어감.
					break ;
				}
			}
		}
	}

	for (auto eastCow: eastCows)
		if (stops[eastCow.id].x != 0)
			result[eastCow.id] = stops[eastCow.id].y - eastCow.y;
	for (auto northCow: northCows)
		if (stops[northCow.id].x != 0)
			result[northCow.id] = stops[northCow.id].y - northCow.y;
	
	for (auto val: result) {
		if (val == INF)
			cout << "Infinity\n";
		else
			cout << val << '\n';
	}

	return (0);
}