#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define THETA first
#define COVER second

using namespace std;
using vi = vector<int>;
using dd = pair<double, double>;
using vdd = vector<dd>;

int n;
vdd arr;

inline double to_rad(double x, double y) { // ok
    // x, y != 0, 0
    if (x == 0.0) return y > 0.0? M_PI / 2.0: M_PI / 2.0 * 3.0;
    if (x > 0.0) return y > 0.0? atan(y / x): 2 * M_PI + atan(y / x);
    return M_PI + atan(y / x);
}

int solve(double begin, double end) {
    if (begin >= end) return 0;
    double next_begin = begin;
    for (dd &next: arr) {
        if (begin < next.first) break;
        next_begin = max(next_begin, next.second);
    }
    return next_begin != begin? 1 + solve(next_begin, end): n + 1;
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
            double y, x, r;
            cin >> y >> x >> r;
            arr[i] = {to_rad(x, y) - 2.0 * asin(r / 16.0), to_rad(x, y) + 2.0 * asin(r / 16.0)};
        }
        sort(arr.begin(), arr.end());

        int ans = n + 1;
        FOR(start, n) {
            if (arr[start].first <= 0) ans = min(ans, 1 + solve(arr[start].second, 2 * M_PI + arr[start].first));
            else if (arr[start].second >= 2 * M_PI) ans = min(ans, 1 + solve(arr[start].second - 2 * M_PI, arr[start].first));
        }

        if (ans >= n + 1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }

    return 0;
}