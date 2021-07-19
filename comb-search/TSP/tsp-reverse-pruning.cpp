#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define INF 1000000000
#define FOR(i, n) for (int (i) = 0; (i) < (n); ++(i))

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

bool reverse_pruning(vi &path) {
    if (path.size() < 4) return false;
    int v1 = *(path.end() - 1);
    int v2 = *(path.end() - 2);
    for (int i = 1; i < path.size() - 3; ++i)
        if (dist[path[i - 1]][path[i]] + dist[v2][v1] > dist[path[i - 1]][v2] + dist[path[i]][v1])
            return true;
    return false;
}

void tsp(int visited, vi &path, double len) {
    if (best <= len) return;
    if (reverse_pruning(path)) return;
    if (visited == (1 << n) - 1) best = min(best, len + dist[path.back()][0]);
    int prev = path.back();
    FOR(next, n) {
        if (visited & (1 << next)) continue;
        path.push_back(next);
        tsp(visited | (1 << next), path, len + dist[prev][next]);
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
        vi path = {0};
        tsp(1, path, 0);
        cout << best << endl;
    }

    return 0;
}