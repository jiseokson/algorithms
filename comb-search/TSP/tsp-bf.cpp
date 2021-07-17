#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define INF 1000000000
#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vd = vector<double>;
using vvd = vector<vd>;

int n;
vvd dist;
double best = 1000000000;

void get_input() {
    best = INF;

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

void tsp_bf(int visited, int prev, double len) {
    if (best <= len) return;
    if (visited == (1 << n) - 1) best = min<double>(best, len + dist[prev][0]);
    FOR(next, n) {
        if (visited & (1 << next)) continue;
        tsp_bf(visited | (1 << next), next, len + dist[prev][next]);
    }
}

int main(void) {
    cout << fixed;
    cout.precision(8);
    
    int c;
    cin >> c;

    while (c--) {
        get_input();
        tsp_bf(1, 0, 0);
        cout << best << endl;
    }

    return 0;
}