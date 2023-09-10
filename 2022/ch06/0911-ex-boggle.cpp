#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vs = vector<string>;

int c, n;
vs targets;
vs board;

int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

inline bool in_range(int y, int x) {
    return 0 <= y && y < 5 && 0 <= x && x < 5;
}

bool has_word(int y, int x, int i, const string& target) {
    if (!in_range(y, x)) return false;
    if (board[y][x] != target[i]) return false;
    if (i == target.length() - 1) return true;
    // in_range() and board[y][x] == target[i] and ...
    // 마지막 문자가 일칠하는지 검사 => 참이라면 더이상 탐색하지 않고 종료
    for (int dir = 0; dir < 8; ++dir)
        if (has_word(y + dy[dir], x + dx[dir], i + 1, target))
            return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c;
    while (c--) {
        board = vs(5);
        for (int i = 0; i < 5; ++i)
            cin >> board[i];
        cin >> n;
        targets = vs(n);
        for (int i = 0; i < n; ++i)
            cin >> targets[i];
        for (int i = 0; i < n; ++i) {
            const string& target = targets[i];
            bool ok = false;
            for (int coord = 0; coord < 25; ++coord) {
                int y = coord / 5, x = coord % 5;
                if (board[y][x] != target[0]) continue;
                if (ok = has_word(y, x, 0, target)) break;
            }
            cout << target << ' ' << (ok? "YES\n": "NO\n");
        }
    }

    return 0;
}