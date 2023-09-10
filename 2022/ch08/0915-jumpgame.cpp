#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c, n;
vvi board, cache;

inline bool in_range(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int can_arrive(int y, int x) {
    if (!in_range(y, x)) return false;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    if (y == n - 1 && x == n - 1) return ret = true;
    return ret = can_arrive(y + board[y][x], x) || can_arrive(y, x + board[y][x]);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> n;
        board = vvi(n, vi(n)), cache = vvi(n, vi(n, -1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> board[i][j];
        cout << (can_arrive(0, 0)? "YES\n": "NO\n");
    }

    return 0;
}