#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int dp[31] = {1, 0, 3};

    for (int i = 4; i <= n; i += 2) {
        dp[i] += 3 * dp[i - 2];
        for (int j = 4; i - j >= 0; j += 2)
            dp[i] += 2 * dp[i - j];
    }

    cout << dp[n];

    return 0;
}