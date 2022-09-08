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

double mst_heuristic(int visited) {
    int init = 0;
    while (~visited & (1 << init)) ++init;
    vector<int> V = {init};

    double mst_edge = 0.0;

    while (visited != (1 << n) - 1) {
        int min_v;
        double min_edge = INF;
        for (int i: V) {
            FOR(j, n) {
                if (j == i || visited & (1 << j))
                    continue;
                if (min_edge > dist[i][j]) {
                    min_v = j;
                    min_edge = dist[i][j];
                }
            }
        }

        visited |= 1 << min_v;
        V.push_back(min_v);
        mst_edge += min_edge;
    }

    return mst_edge;
}

void tsp(int visited, int prev, double len) {
    if (best <= len + mst_heuristic(visited)) return;
    if (visited == (1 << n) - 1 ) best = min(best, len + dist[prev][0]);
    FOR(next, n) {
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
        tsp(1, 0, 0);
        cout << best << endl;
    }

    return 0;
}