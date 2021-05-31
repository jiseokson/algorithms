#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;

int n, d, p, t;
int q;

bool conn[50][50];
int deg[50];

double solve(vi &path) {
    if (path.size() == d + 1) {
        if (path.back() != q) return 0.0;
        double ret = 1.0;
        for (size_t i = 0; i < path.size() - 1; ++i) ret /= deg[path[i]];
        return ret;
    }

    double ret = 0.0;
    for (int adj = 0; adj < n; ++adj) {
        if (conn[path.back()][adj]) {
            path.push_back(adj);
            ret += solve(path);
            path.pop_back();
        }
    }

    return ret;
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
        memset(conn, false, sizeof(conn));
        memset(deg, 0, sizeof(deg));
        cin >> n >> d >> p;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> conn[i][j];
                if (conn[i][j] && conn[j][i]) {
                    ++deg[i];
                    ++deg[j];
                }
            }
        }

        int t;
        cin >> t;
        while (t--) {
            cin >> q;
            vi path(1, p);
            cout << solve(path) << ' ' ; 
        }
        cout << '\n';
    }

    return 0;
}