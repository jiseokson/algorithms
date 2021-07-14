#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using dd = pair<double, double>;
using vdd = vector<dd>;

#define FOR(i, n) for (int i = 0; i < n; ++i)

int n;
vdd arr;

inline double to_rad(double x, double y) { // ok
    if (x == 0.0) return y > 0? M_PI / 2.0: M_PI / 2.0 * 3.0;
    if (x > 0.0) return y > 0.0? atan(y / x): 2 * M_PI + atan(y / x);
    return M_PI + atan(y / x);
}

int solve(int cnt, int start, int prev, double cover) {
    // if (!init && start <= prev)
    if (cover >= M_PI * 2) return cnt;

    vi next_cand;
    FOR(d, n) {
        int next = (start + d) % n;
        double diff = abs(arr[prev].first - arr[next].first);
        diff = min(diff, 2 * M_PI - diff);
        if (2.0 * diff <= arr[prev].second + arr[next].second)
            next_cand.push_back(next);
    }

    int res = n + 1;
    for (int next: next_cand) {
        double diff = abs(arr[prev].first - arr[next].first);
        diff = min(diff, 2 * M_PI - diff);
        res = min(res, solve(cnt + 1, start, prev, cover + diff + arr[next].second / 2.0));
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        cin >> n;

        arr = vdd(n);
        FOR(i, n) {
            double x, y, r;
            cin >> y >> x >> r;
            arr[i] = {to_rad(x, y), r / 4.0};
        }

        int ans = n + 1;
        FOR(start, n)
            ans = min(ans, solve(0, start, start, arr[start].second / 2.0));
        if (ans == n + 1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }

    return 0;
}