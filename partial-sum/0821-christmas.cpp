#include <iostream>
#include <vector>

#define MOD 20091101
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

using namespace std;
using vi = vector<int>;

int n, k;
vi psum, dcount, dp;

inline int rangeSum(int i, int f) {
    return i != 0? psum[f] - psum[i - 1]: psum[f];
}

int max_pair(int i) {
    if (i >= n) return 0;
    int &res = dp[i];
    if (res != -1) return res;

    res = max_pair(i + 1);
    for (int j = i; j < n; ++j)
        if (rangeSum(i, j) == 0) {
            res = max(res, 1 + max_pair(j + 1));
            break;
        }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        psum = vi(n + 1, 0);
        dcount = vi(k + 1, 0);
        dp = vi(n + 1, -1);
        dcount[0] = 1;
        REP(i, n) {
            int d; cin >> d;
            psum[i] = (i != 0? psum[i - 1] + d: d) % k;
            ++dcount[psum[i]];
        }

        int ans1 = 0;
        REP(i, k) ans1 = ((long long)ans1 + (long long)dcount[i] * (dcount[i] - 1) / 2) % MOD;
        cout << ans1 << ' ' << max_pair(0) << '\n';
    }

    return 0;
}