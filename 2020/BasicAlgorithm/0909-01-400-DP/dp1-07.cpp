
// dp1-07 top down
#include <iostream>
using namespace std;

int memo[4][1000001] = {0};

int ans(int m, int n)
{
    if (memo[m][n] != 0)
        return memo[m][n];
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    switch (m) {
    case 1:
        memo[m][n] = (ans(2, n - 2) % 1000000009 + ans(3, n - 3) % 1000000009) % 1000000009;
        break;
    case 2:
        memo[m][n] = (ans(1, n - 1) % 1000000009 + ans(3, n - 3) % 1000000009) % 1000000009;
        break;
    case 3:
        memo[m][n] = (ans(1, n - 1) % 1000000009 + ans(2, n - 2) % 1000000009) % 1000000009;
        break;
    }
    return memo[m][n];
}

int main(void)
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << (((ans(1, n - 1) % 1000000009 + ans(2, n - 2) % 1000000009) % 1000000009) + ans(3, n - 3) % 1000000009) % 1000000009 << '\n';
    }

    return 0;
}
