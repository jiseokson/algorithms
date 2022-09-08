#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define NEGINF numeric_limits<ll>::min()

int jlis(vi &a, vi &b, vector<vi> &dp, int i, int j) {
    int &ret = dp[i][j];
    if (ret != -1) return ret;

    ret = 2;
    ll m = max(i == 0 ? NEGINF : a[i], j == 0 ? NEGINF : b[j]);
    for (int k = i + 1; k < a.size(); ++k)
        if (m < a[k]) ret = max(ret, jlis(a, b, dp, k, j) + 1);
    for (int k = j + 1; k < b.size(); ++k)
        if (m < b[k]) ret = max(ret, jlis(a, b, dp, i, k) + 1);

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        vi a(n + 1), b(m + 1);
        vector<vi> dp(n + 1, vi(m + 1, -1));

        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int j = 1; j <= m; ++j) cin >> b[j];
        cout << jlis(a, b, dp, 0, 0) - 2 << '\n';
    }

    return 0;
}