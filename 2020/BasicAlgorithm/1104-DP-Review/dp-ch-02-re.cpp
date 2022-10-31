#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    int dp[201] = {1};

    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++)
            dp[j] = (dp[j] + dp[j - 1]) % 1000000000;
    }

    cout << dp[n];

    return 0;
}