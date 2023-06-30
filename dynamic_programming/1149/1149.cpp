#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int rg;
	int rb;
	int gr;
	int gb;
	int br;
	int bg;
} RGB;

RGB rgb[1001];
int n, r, g, b;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int i = 0;
	while (++i <= n)
	{
		cin >> r >> g >> b;
		rgb[i].rb = min(rgb[i - 1].br, rgb[i -1].gr) + b;
		rgb[i].rg = min(rgb[i - 1].br, rgb[i -1].gr) + g;
		rgb[i].gr = min(rgb[i - 1].rg, rgb[i -1].bg) + r;
		rgb[i].gb = min(rgb[i - 1].rg, rgb[i -1].bg) + b;
		rgb[i].br = min(rgb[i - 1].rb, rgb[i -1].gb) + r;
		rgb[i].bg = min(rgb[i - 1].rb, rgb[i -1].gb) + g;
	}
	cout << min({rgb[n].rb, rgb[n].rg, rgb[n].gr, rgb[n].gb, rgb[n].br, rgb[n].bg});
	
	return (0);
}