#include <iostream>
#include <vector>
using namespace std;

#define MOD 10000000
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi dp;

int solve(int m, int n) {
    int &ret = dp[m][n];
    if (n == 0) return 1;
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 1; i <= n; ++i) ret = (ret + (m + i - 1) * solve(i, n - i)) % MOD;
    return ret;
}

int main(void) {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        dp = vvi(n + 1, vi(n + 1, -1));
        int ans = 0;
        for (int m = 1; m <= n; ++m)
            ans = (ans + solve(m, n - m)) % MOD;
        cout << ans << '\n';
    }

    return 0;
}