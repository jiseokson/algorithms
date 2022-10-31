#include <iostream>
using namespace std;

int d[10][1001];

int inn(int f, int n)
{
    if (n == 0)
        return 1;
    if (d[f][n] != 0)
        return d[f][n];

    int res = 0;
    for (int i = f; i < 10; i++)
        res = (res + inn(i, n - 1) % 10007) % 10007;

    d[f][n] = res;
    return res;
}

int main(void)
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans + inn(i, n - 1) % 10007) % 10007;
    cout << ans;
    return 0;
}