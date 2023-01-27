#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void input(void);
void find_gcd(void);
int gcd(int a, int b);

int arr[100], difference[99], n;
vector<int> output;

int main(void)
{
    input();
    find_gcd();
    
    return (0);
}

void input(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int i = -1;
    while (++i < n)
        cin >> arr[i];
    
    sort(arr, arr + n, greater<>());

    i = -1;
    while (++i < n - 1)
        difference[i] = arr[i] - arr[i + 1];

    return ;
}

void find_gcd(void)
{
    int result = gcd(difference[0], difference[1]);

    int i = 1;
    while (++i < n - 1)
        result = gcd(difference[i], result);

    i = 1;
    while ((++i) * i <= result)
    {
        if (result % i == 0)
        {
            output.push_back(i);
            output.push_back(result / i);
        }
    }

    if (output.size() >= 2 && output[output.size() - 1] == output[output.size() - 2])
        output.pop_back();
    output.push_back(result);

    sort(output.begin(), output.end());

    i = -1;
    while (++i < output.size())
        cout << output[i] << ' ';

    return ;
}

int gcd(int a, int b)
{
    if (b == 0)
        return (a);
    else
        return (gcd(b, a % b));
}