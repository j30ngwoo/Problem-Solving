#include <iostream>

using namespace std;
int n, p[101], count = 0;

int is_there_avgflower(int i, int j) {
	double avg = 0;

	for (int k = i; k <= j; k++)
		avg += p[k];
	avg = (double)avg / (j - i + 1);
	for (int k = i; k <= j; k++)
		if (avg == (double)p[k]) return (1);
	return (0);
}

int main(void) {	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (is_there_avgflower(i, j))
				count++;
		}
	}
	cout << count;
	return (0);
}