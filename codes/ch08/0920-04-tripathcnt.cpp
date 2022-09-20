#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c, n;
vvi triangle, cache, count_cache;

int max_path(int y, int x) {
    if (y == n) return 0;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    return ret = triangle[y][x] + max(max_path(y + 1, x), max_path(y + 1, x + 1));
}

int count(int y, int x) {
    if (y == n - 1) return 1;
    int& ret = count_cache[y][x];
    if (ret != -1) return ret;
    if (max_path(y + 1, x) > max_path(y + 1, x + 1)) return ret = count(y + 1, x);
    if (max_path(y + 1, x) < max_path(y + 1, x + 1)) return ret = count(y + 1, x + 1);
    return ret = count(y + 1, x) + count(y + 1, x + 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> n;
        triangle = vvi(n, vi(n, 0));
        cache = vvi(n, vi(n, -1));
        count_cache = vvi(n, vi(n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                cin >> triangle[i][j];
            }
        }

        cout << count(0, 0) << '\n';
    }

    return 0;
}