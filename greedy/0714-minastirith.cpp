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

vdd arr;

inline double to_rad(double x, double y) { // ok
    // x, y != 0, 0
    if (x == 0.0) return y > 0.0? M_PI / 2.0: M_PI / 2.0 * 3.0;
    if (x > 0.0) return y > 0.0? atan(y / x): 2 * M_PI + atan(y / x);
    return M_PI + atan(y / x);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        arr = vdd(n);
        FOR(i, n) {
            double y, x, r;
            cin >> y >> x >> r;
            arr[i] = {to_rad(x, y), r / 4.0};
        }
        sort(arr.begin(), arr.end(),
            [] (dd &a, dd &b) {
                return a.THETA - a.COVER / 2.0 < b.THETA - b.COVER / 2.0;
            }
        );

        int cnt = 1;
        int now = 0;
        int next_cand;
        double latest_cover = 2 * arr[0].COVER;
        for (int next = 1; next < n; ++next) {
            bool overed = arr[next].THETA - arr[next].COVER <= latest_cover;
            if (!overed) {
                latest_cover = arr[next_cand].THETA + arr[next_cand].COVER / 2.0;
                now = next_cand;
                ++cnt;
            }

            double temp_cover = arr[next].THETA + arr[next].COVER / 2.0;
            if (temp_cover >= 2 * M_PI) break;
            if (latest_cover < temp_cover)
                next_cand = next;

            // cout << now << ' ' << latest_cover << '\n';
            // cout << next << ' ' << temp_cover << '\n';
            // cout << '\n';
        }

        if (latest_cover >= 2 * M_PI) cout << cnt  << '\n';
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}