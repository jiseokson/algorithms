#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vd> vvd;

int c, n, k, m;
int target;
vi l;
vvd T, dp;

double solve(int t, int prev) {
    if (prev == target && t - l[prev] <= k && k < t) return 1;
    if (k < t) return 0;
    double &res = dp[t][prev];
    if (res != -1.0) return res;

    res = 0.0;
    // for (int next = 0; next < n; ++n)
    for (int next = 0; next < n; ++next)
        res += T[prev][next] * solve(t + l[next], next);
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(8);

    cin >> c;

    while (c--) {
        cin >> n >> k >> m;
        l = vi(n);
        T = vvd(n, vd(n));
        for (int i = 0; i < n; ++i) cin >> l[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> T[i][j];
        for (int i = 0; i < m; ++i) {
            cin >> target;
            dp = vvd(1000000, vd(n, -1.0));
            cout << solve(k - l[0], 0) << ' ';
        }
        cout << '\n';
    }

    return 0;
}