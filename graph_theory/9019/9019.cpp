#include <iostream>
#include <functional>
#include <queue>
#include <unistd.h>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

struct E {
	int num;
	vector<char> commandStr;
};

int D(int num) {
	return (num * 2 % 10000);
}

int S(int num) {
	if (num == 0)
		return (9999);
	else
		return (num - 1);
}

int L(int num) {
	return (num * 10 % 10000 + num / 1000); 
}

int R(int num) {
	return (num / 10 + (num % 10) * 1000);
}

function<int(int)> commands[4] = {D, S, L, R};
char DSLR[4] = {'D', 'S', 'L', 'R'};
bool isVisited[10000];
queue<E> q;
vector<vector<char>> result;
int t;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	FOR(i, t) {
		int a, b;
		cin >> a >> b;
		fill_n(isVisited, 10000, false);
		while (!q.empty())
			q.pop();
		q.push({a, vector<char>()});
		while (!q.empty()) {
			int num = q.front().num;
			vector<char> commandStr = q.front().commandStr;
			q.pop();
			if (isVisited[num]) continue;
			isVisited[num] = true;
			if (num == b) { 
				result.push_back(commandStr);
				break ;
			}	
			FOR(i, 4) {
				int nextNum = commands[i](num);
				if (isVisited[nextNum] || nextNum < 0 || 10000 <= nextNum) continue;
				q.push({nextNum, commandStr.push_back(DSLR[i])});
				//cout << nextNum << '\n';
			}
		}
	}
	
	for (auto elem : result)
		cout << elem << '\n';
	return (0);
}
