#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dp[2][100001];
    int ans = arr[0];

    dp[0][0] = dp[1][0] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[0][i] = max(arr[i], arr[i] + dp[0][i - 1]);
        if (arr[i] < 0)
            dp[1][i] = max(dp[0][i - 1], arr[i] + dp[1][i - 1]);
        else
            dp[1][i] = max(arr[i], arr[i] + dp[1][i - 1]);

        if (ans < dp[0][i]) ans = dp[0][i];
        if (ans < dp[1][i]) ans = dp[1][i];
    }

    cout << ans;
    return 0;
}