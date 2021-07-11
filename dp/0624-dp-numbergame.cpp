#include <iostream>
#include <vector>

#define NONE (-2 * 50 * 1000)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int c, n;
vi a;
vvi dp;

int diff(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    int &ret = dp[l][r];
    if (ret != NONE) return ret;

    ret = max(ret, a[l] - diff(l + 1, r));
    ret = max(ret, a[r] - diff(l, r - 1));
    if (r - l + 1 >= 2) {
        ret = max(ret, -diff(l + 2, r));
        ret = max(ret, -diff(l, r - 2));
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;

    while (c--) {
        cin >> n;
        a = vi(n);
        dp = vvi(n, vi(n, NONE));
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << diff(0, n - 1) << '\n';
    }

    return 0;
}