#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int c, h, w;
vvi board;

int blocks[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
    {{0, 0}, {1, 0}, {1, 1}}
};

inline bool in_range(int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

bool cover(int y, int x, int b, int c) {
    for (int i = 0; i < 3; ++i) {
        int next_y = y + blocks[b][i][0], next_x = x + blocks[b][i][1];
        if (!in_range(next_y, next_x) || board[next_y][next_x] == c) return false;
    }
    for (int i = 0; i < 3; ++i) {
        int next_y = y + blocks[b][i][0], next_x = x + blocks[b][i][1];
        board[next_y][next_x] = c;
    }
    return true;
}

int solve(int i) {
    for (; i < h * w; ++i)
        if (board[i / w][i % w] == '.') break;

    if (i == h * w) return 1;
    int ret = 0;
    int y = i / w, x = i % w;
    for (int b = 0; b < 4; ++b) {
        if (!cover(y, x, b, '#')) continue;
        ret += solve(i);
        cover(y, x, b, '.');
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        cin >> h >> w;
        board = vvi(h, vi(w));
        for (int i = 0; i < h; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < w; ++j)
                board[i][j] = row[j];
        }
        cout << solve(0) << '\n';
    }

    return 0;
}