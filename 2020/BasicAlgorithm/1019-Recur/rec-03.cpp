#include <iostream>
using namespace std;


int main(void)
{
    int n;
    cin >> n;

    int t[n], p[n];
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        cin >> p[i];
    }

    int dp[20] = {0};
    int ans = 0;

    for (int i = n; i >= 1; i--) {
        if (i + 1 <= n)
            dp[i] = dp[i + 1];
        if (i + t[i] - 1 <= n)
            dp[i] = max(dp[i], p[i] + dp[i + t[i]]);
        if (ans < dp[i])
            ans = dp[i];
    }

    cout << ans;

    return 0;
}