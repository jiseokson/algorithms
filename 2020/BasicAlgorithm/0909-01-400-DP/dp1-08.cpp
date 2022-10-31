#include <iostream>
using namespace std;

int memo[10][101] = {0};

int sn(int m, int n)
{
    if (n == 0)
        return 1;
    if (memo[m][n] != 0)
        return memo[m][n];

    int res = 0;
    if (m - 1 >= 0) {
        res = (res % 1000000000 + sn(m - 1, n - 1) % 1000000000) % 1000000000;
    }
    if (m + 1 < 10) {
        res = (res % 1000000000 + sn(m + 1, n - 1) % 1000000000) % 1000000000;
    }
    memo[m][n] = res;
    return memo[m][n];
}

int main(void)
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
        ans = (ans % 1000000000 + sn(i, n - 1) % 1000000000) % 1000000000;
    }
    cout << ans;
    return 0;
}