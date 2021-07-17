#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vvd = vector<vd>;
using dd = pair<double, double>;
using vdd = vector<dd>;

int n;
vvd dist;
double best;

void get_input() {
    int n;
    cin >> n;

    dist = vvd(n, vd(n));
    best = 1000000000;

    vdd citys;
    FOR(i, n) {
        double x, y;
        cin >> x >> y;
        citys.push_back({x, y});
    }

    FOR(i, n) {
        FOR(j, n) {
            double dx = citys[i].first - citys[j].first;
            double dy = citys[i].second - citys[j].second;
            dist[i][j] = sqrt(dx * dx + dy * dy);
            cout << dist[i][j] << '\n';
        }
    }
}

void tsp_bf(int visited, vi &path, int len) {
    if (best <= len) return;
    if (visited == (1 << n) - 1) best = min(best, len + dist[path.back()][0]);

    int prev = path.back();
    FOR(next, n) {
        if (visited & (1 << next)) continue;
        path.push_back(next);
        tsp_bf(visited | (1 << next), path, len + dist[prev][next]);
        path.pop_back();
    }
}

int main(void) {
    int c;
    cin >> c;

    while (c--) {
        get_input();

        vi path = {0};
        tsp_bf(1, path, 0);

        cout << best << endl;
    }

    return 0;
}