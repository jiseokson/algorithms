#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(10);

    int c;
    cin >> c;

    while (c--) {
        int n, d, p;
        bool conn[50][50] = {false};
        int deg[50] = {0};

        cin >> n >> d >> p;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> conn[i][j];
                if (conn[i][j] && !conn[j][i]) {
                    ++deg[i];
                    ++deg[j];
                }
            }
        }

        double dp[101][50] = {0.0};
        for (int adj = 0; adj < n; ++adj)
            if (conn[p][adj]) dp[0][adj] = 1.0 / deg[p];
        for (int i = 1; i <= d; ++i) {
            for (int cur = 0; cur < n; ++cur) {
                for (int adj = 0; adj < n; ++adj) {
                    if (conn[cur][adj])
                        dp[i][cur] += dp[i - 1][adj] / deg[adj];
                }
            }
        }

        int t;
        cin >> t;
        while (t--) {
            int q;
            cin >> q;
            cout << dp[d - 1][q] << ' ';
        }
        cout << '\n';
    }

    return 0;
}