#include <iostream>
#include <algorithm>

using namespace std;

void find_max(void);
void input(void);

int square[1001][1001];
int n, m, result;

int main(void)
{
    input();
    find_max();

    return (0);
}

void input(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int i = 0;
    while (++i <= n)
    {
        int j = 0;
        while (++j <= m)
        {
            char input;
            cin >> input;
            square[i][j] = input - '0';
        }
    }

    return ;
}

void find_max(void)
{
    int x = 0;
    while (++x <= n)
    {
        int y = 0;
        while (++y <= m)
        {
            if (square[x][y] != 0)
            {
                square[x][y] = min({square[x - 1][y], square[x][y - 1], square[x - 1][y - 1]}) + 1;
                result = max(result, square[x][y]);
            }
        }
    }

    cout << result * result;

    return ;
}