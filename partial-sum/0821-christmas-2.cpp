#include <iostream>
#include <vector>

#define MOD 20091101
using namespace std;
using vi = vector<int>;
using ll = long long;

int n, k;
vi psum, dcnt;

int all_pair() {
    int res = 0;
    for (int i = 0; i < k; ++i)
        res = ((ll)res + (ll)dcnt[i] * (dcnt[i] - 1) / 2) % MOD;
    return res;
}

int max_pair() {
    vi dp(n + 1, -1);
    vi prev(k + 1, -1);

    dp[0] = 0;
    if (psum[0] == 0) dp[0] = 1;
    prev[psum[0]] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        int loc = prev[psum[i]];
        if (loc != -1) dp[i] = max(dp[i], 1 + dp[loc]);
        prev[psum[i]] = i;
    }
    return dp[n - 1];
}

int main(void) {
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;

        psum = vi(n + 1, 0);
        dcnt = vi(k + 1, 0);
        dcnt[0] = 1;

        for (int i = 1; i <= n; ++i) {
            int d; cin >> d;
            psum[i] = (psum[i - 1] + d) % k;
            ++dcnt[psum[i]];
        }

        cout << all_pair() << ' ' << max_pair() << '\n';
    }
    return 0;
}