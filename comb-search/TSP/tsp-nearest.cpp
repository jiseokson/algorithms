#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define INF 1000000000
#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vd = vector<double>;
using vvd = vector<vd>;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vd min_edge;
vvd dist;
vvi nearest;
double best = INF;

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

void init() {
    best = INF;

    // make min_edge
    min_edge = vd(n, INF);
    FOR(i, n) FOR(j, n) min_edge[i] = min(min_edge[i], dist[i][j]);

    // make nearest
    nearest = vvi(n, vi(n));
    FOR(i, n) {
        vector<pair<double, int>> arr;
        FOR(j, n) arr.push_back({dist[i][j], j});
        sort(arr.begin(), arr.end());
        FOR(j, n) nearest[i][j] = arr[j].second;
    }
}

inline double simple_heuristic(int visited) {
    double res = 0.0;
    FOR(i, n) {
        if (visited & (1 << i)) continue;
        res += min_edge[i];
    }
    return res;
}

void tsp(int visited, int prev, double len) {
    if (best <= len + simple_heuristic(visited)) return;
    if (visited == (1 << n) - 1) best = min(best, len + dist[prev][0]);
    for (int &next: nearest[prev]) {
        if (visited & (1 << next)) continue;
        tsp(visited | (1 << next), next, len + dist[prev][next]);
    }
}

int main(void) {
    cout << fixed;
    cout.precision(8);

    int c;
    cin >> c;

    while (c--) {
        get_input();
        init();
        tsp(1, 0, 0);
        cout << best << endl;
    }
    
    return 0;
}