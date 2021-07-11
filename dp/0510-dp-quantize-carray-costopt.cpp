#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

typedef vector<int> vi;
typedef vector<vi> vvi;

vi c, d;
vvi dp;

int solve(int i, int s) {
    if (s < 0) return INF;
    if (i == d.size()) return 0;

    int &ret = dp[i][s];
    if (ret != -1) return ret;

    ret = INF;
    int n = 0;
    int a_sum = 0, a_sq_sum = 0;
    for (int j = 1; i + j <= d.size(); ++j) {
        n += c[d[i + j - 1]];
        a_sum += d[i + j - 1] * n;
        a_sq_sum += d[i + j - 1] * d[i + j - 1] * n;
        int m = int(0.5 + (double)a_sum / n);
        int cost = a_sq_sum - 2 * m * a_sum + j * m * m;
        ret = min(ret, cost + solve(i + j, s - 1));
    }
    return ret;
}

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        c = vi(1001, 0);
        d = vi();
        dp = vvi(1001, vi(11, -1));

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (!c[a]) d.push_back(a);
            ++c[a];
        }

        sort(d.begin(), d.end());
        cout << solve(0, s) << '\n';
    }

    return 0;
}