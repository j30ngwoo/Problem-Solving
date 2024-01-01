#include <iostream>
#include <functional>
#include <queue>
#include <string>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;

struct E {
	int num;
	string command;
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

function<int(int)> func[4] = {D, S, L, R};
string DSLR[4] = {"D", "S", "L", "R"};
int t;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	FOR(x, t) {
		int a, b;
		cin >> a >> b;
		bool isVisited[10000] = {0,};
		queue<E> q;
		q.push({a, ""});
		isVisited[a] = true;
		while (!q.empty()) {
			int nowNum = q.front().num;
			string nowCommand  = q.front().command;
			q.pop();
			if (nowNum == b) {
				cout << nowCommand << '\n';
				break ;
			}
			FOR (i, 4) {
				int nextNum = func[i](nowNum);
				if (isVisited[nextNum]) continue;
				isVisited[nextNum] = true;
				q.push({nextNum, nowCommand + DSLR[i]});
			}
		} 
	}
	return (0);
}
