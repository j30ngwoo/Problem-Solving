#include <iostream>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
using namespace std;
bool isVisited[100];
int graph[100][100];
int n;

void recursion(int nowNode	) {
	
}

int main(void) {
	cin >> n;
	FOR(from, n) {
		FOR(to, n) {
			int input;
			cin >> input;
			graph[from][to] = input;
		}
	}
	
	FOR(from, n) {
	
	}


	return (0);
}