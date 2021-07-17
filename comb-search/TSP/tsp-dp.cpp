#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using vd = vector<double>;
using vvd = vector<vd>;
using dd = pair<double, double>;
using vdd = vector<dd>;

const double INF = 1000000000;

int n;
vvd dist, dp;

void get_input() {
    cin >> n;
    vdd citys(n);
    FOR(i, n) {
        double x, y;
        cin >> x >> y;
        citys[i] = {x, y};
    }

    dist = vvd(n, vd(n));
    FOR(i, n) {
        FOR(j, n) {
            double dx = citys[i].first - citys[j].first;
            double dy = citys[i].second - citys[j].second;
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }
}

double tsp_dp(int visited, int prev) {
    if (visited == (1 << n) - 1) return dist[prev][0];
    double &res = dp[visited][prev];
    if (res != -1.0) return res;

    res = INF;
    FOR(next, n) {
        if (visited & (1 << next)) continue;
        res = min(res, dist[prev][next] + tsp_dp(visited | (1 << next), next));
    }
    return res;
}

int main(void) {
    int c;
    cin >> c;

    while (c--) {
        get_input();
        dp = vvd(1 << n, vd(n, -1.0));
        cout << tsp_dp(1, 0) << endl;
    }

    return 0;
}