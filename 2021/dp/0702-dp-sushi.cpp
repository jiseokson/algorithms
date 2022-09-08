#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int c, n, m;
vi price, pref;
vi dp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        cin >> n >> m;
        m /= 100;
        price = vi(n), pref = vi(n);
        dp = vi(210, 0);
        for (int i = 0; i < n; ++i) {
            cin >> price[i] >> pref[i];
            price[i] /= 100;
        }
        for (int b = 1; b <= m; ++b) {
            for (int menu = 0; menu < n; ++menu) {
                if (b < price[menu]) continue;
                dp[b % 201] = max(dp[b % 201], pref[menu] + dp[(b - price[menu]) % 201]);
            }
        }
        cout << dp[m % 201] << '\n';
    }

    return 0;
}