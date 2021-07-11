#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef vector<int> vi;
typedef vector<vi> vvi;

vi a;
vi a_ps, a_sq_ps;
vvi dp;

inline int range_sum(vi &ps, int i, int f) {
    return ps[f - 1] - ps[i - 1];
}

int solve(int i, int s) {
    if (s < 0) return INF;
    if (i == a.size()) return 0;

    int &ret = dp[i][s];
    if (ret != -1) return ret;

    ret = INF;
    for (int j = 1; i + j <= a.size(); ++j) {
        int a_sq_sum = range_sum(a_sq_ps, i, i + j);
        int a_sum = range_sum(a_ps, i, i + j);
        // int q1 = a_sum / j, q2 = q1 + 1;
        // int cost = min(
        //     a_sq_sum - 2 * q1 * a_sum + j * q1 * q1,
        //     a_sq_sum - 2 * q2 * a_sum + j * q2 * q2
        // );
        int q = int(0.5 + (double)a_sum / j);
        int cost = a_sq_sum - 2 * q * a_sum + j * q * q;
        ret = min(ret, cost + solve(i + j, s - 1));

    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n, s;
        cin >> n >> s;

        a = vi(n + 1);
        a_ps = vi(n + 1, 0), a_sq_ps = vi(n + 1, 0);
        dp = vvi(n + 1, vi(s + 1, -1));

        for (int i = 1; i <= n; ++i) cin >> a[i];

        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= n; ++i) {
            a_ps[i] = a_ps[i - 1] + a[i];
            a_sq_ps[i] = a_sq_ps[i - 1] + a[i] * a[i];
        }

        cout << solve(1, s) << '\n';
    }

    return 0;
}