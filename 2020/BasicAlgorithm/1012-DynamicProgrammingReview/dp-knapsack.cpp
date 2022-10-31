#include <iostream>
using namespace std;

int main(void)
{
    int n, w;
    cin >> n >> w;
    int weights[n + 1], vals[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> weights[i] >> vals[i];

    int dp[100][100] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (weights[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(vals[i] + dp[i - 1][j - weights[i]], dp[i - 1][j]);
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << dp[n][w];
    return 0;
}