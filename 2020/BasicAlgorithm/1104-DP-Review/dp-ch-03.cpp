#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int cost[1001][3] = {0};
    for (int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int ans = 1000 * 1000;
    int dp[1001][3] = {0};

    for (int i = 0; i < 3; i++) {
        dp[1][i] = cost[1][i];
        dp[1][(i + 1) % 3] = dp[1][(i + 2) % 3] = 1000;

        for (int j = 2; j <= n; j++) {
            for (int k = 0; k < 3; k++)
                dp[j][k] = min(dp[j - 1][(k + 1) % 3], dp[j - 1][(k + 2) % 3]) + cost[j][k];
        }

        ans = min(min(dp[n][(i + 1) % 3], dp[n][(i + 2) % 3]), ans);
    }

    cout << ans;

    return 0;
}