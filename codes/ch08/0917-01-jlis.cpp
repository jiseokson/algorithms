#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll NEG_INF = 1LL << 63;

int c, n, m;
vll a, b;
vvi cache;

int jlis(int i, int j) {
    int& ret = cache[i][j];
    if (ret != -1) return ret;

    ret = 1;
    for (int next_i = i + 1; next_i <= n; ++next_i)
        if (max(a[i], b[j]) < a[next_i])
            ret = max(ret, 1 + jlis(next_i, j));
    for (int next_j = j + 1; next_j <= m; ++next_j)
        if (max(a[i], b[j]) < b[next_j])
            ret = max(ret, 1 + jlis(i, next_j));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> n >> m;
        a = vll(n + 1), b = vll(m + 1);
        a[0] = b[0] = NEG_INF;
        cache = vvi(101, vi(101, -1));
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int j = 1; j <= m; ++j) cin >> b[j];
        cout << jlis(0, 0) - 1 << '\n';
    }

    return 0;
}