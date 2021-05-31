#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;

int d, h;
vvd dp;

double solve(int m, int n) {
    if (m == d) return n >= h ? 1.0 : 0.0;
    double &ret = dp[m][n];
    if (ret != -1.0) return ret;
    return ret = (solve(m + 1, n + 1) + 3.0 * solve(m + 1, n + 2)) / 4.0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(10);

    int c;
    cin >> c;

    while (c--) {
        cin >> h >> d;
        dp = vvd(d + 1, vd(2 * d + 1, -1.0));
        cout << solve(0, 0) << '\n';
    }

    return 0;
}