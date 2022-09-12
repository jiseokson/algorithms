#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int c, n, m;
vvi pairs;
vi check;

int solve(int i) {
    while (i < n && check[i]) ++i;
    if (i == n) return 1;
    int ret = 0;
    for (int j = i + 1; j < n; ++j) {
        if (!pairs[i][j] || check[j]) continue;
        check[i] = check[j] = 1;
        ret += solve(i);
        check[i] = check[j] = 0;
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> n >> m;
        pairs = vvi(n, vi(n, 0));
        check = vi(n, 0);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            pairs[a][b] = pairs[b][a] = 1;
        }
        cout << solve(0) << '\n';
    }
    
    return 0;
}