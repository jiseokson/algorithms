#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    int dp[201][201] = {0};
    
    for (int i = 0; i <= n; i++)
        dp[i][1] = 1;

    for (int j = 2; j <= k; j++) {
        dp[0][j] = 1;
        for (int i = 1; i <= n; i++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
    }

    cout << dp[n][k];

    return 0;
}