#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vvd = vector<vd>;

int n, d, p;
vvi adj_mat;
vi deg;
vvd cache;

double prob(int d, int v)
{
    if (d == 0) return v == p;
    double &ret = cache[d][v];
    if (ret != -1.0) return ret;
    ret = 0.0;
    for (int w = 0; w < n; ++w) {
        if (!adj_mat[v][w]) continue;
        ret += prob(d - 1, w) / deg[w];
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(8);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> d >> p;
        adj_mat = vvi(n, vi(n, 0));
        deg = vi(n, 0);
        cache = vvd(d + 1, vd(n + 1, -1.0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> adj_mat[i][j];
                if (adj_mat[i][j]) ++deg[i];
            }
        }
        int t;
        cin >> t;
        while (t--) {
            int v;
            cin >> v;
            cout << prob(d, v);
            if (t) cout << " ";
        }
        if (tc) cout << "\n";
    }

    return 0;
}