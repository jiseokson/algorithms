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
using vi = vector<int>;

int n;
vvd dist;
double best = INF;

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

bool swap_pruning(vi &path) {
    if (path.size() < 4) return false;
    int v1 = *(path.end() - 1);
    int v2 = *(path.end() - 2);
    int v3 = *(path.end() - 3);
    int v4 = *(path.end() - 4);
    return dist[v1][v2] + dist[v3][v4] > dist[v1][v3] + dist[v2][v4];
}

void tsp_bf(int visited, vi &path, double len) {
    if (swap_pruning(path)) return;
    if (visited == (1 << n) - 1) best = min<double>(best, len + dist[path.back()][0]);
    int prev = path.back();
    FOR(next, n) {
        if (visited & (1 << next)) continue;
        path.push_back(next);
        tsp_bf(visited | (1 << next), path, len + dist[prev][next]);
        path.pop_back();
    }
}

int main(void) {
    cout << fixed;
    cout.precision(8);

    int c;
    cin >> c;

    while (c--) {
        get_input();
        cout << "FUc";
        vi path;
        tsp_bf(1, path, 0);
        cout << best << endl;
    }

    return 0;
}