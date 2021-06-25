#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vvi board;
vi dp;

vector<ii> blocks[] = {
    { {0, 0}, {0, 1} },
    { {0, 0}, {1, 0} },
    { {0, 0}, {1, 0}, {1, 1,} },
    { {0, 0}, {1, 0}, {1, -1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {0, 1} }
};

inline int bi() {
    int res = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            res *= 2;
            res += (board[i][j] == '#'? 1: 0);
        }
    return res;
}

inline bool in_range(int i, int j) {
    return 0 <= i && i < 5 && 0 <= j && j < 5;
}

inline bool addable(int bid, int i, int j) {
    for (ii b: blocks[bid]) {
        int dr = b.first, dc = b.second;
        int br = i + dr, bc = j + dc;
        if (!in_range(br, bc) || board[br][bc] == '#') return false;
    }
    return true;
}

inline void put(int bid, int i, int j, int ch) {
    for (ii b: blocks[bid]) {
        int dr = b.first, dc = b.second;
        int br = i + dr, bc = j + dc;
        board[br][bc] = ch;
    }
}

int can_win() {
    int &res = dp[bi()];
    if (res != -2) return res;

    int next = 2;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == '#') continue;
            for (int bid = 0; bid < 6; ++bid) {
                if (!addable(bid, i, j)) continue;
                put(bid, i, j, '#');
                int next = can_win();
                put(bid, i, j, '.');
                if (!next) {
                    return res = 1;
                }
            }
        }
    }

    return res = 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int c;
    cin >> c;

    while (c--) {
        board = vvi(5, vi(5));
        dp = vi(33554432, -2);
        for (int i = 0; i < 5; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < 5; ++j)
                board[i][j] = row[j];
        }
        cout << (can_win() == 1? "WINNING\n": "LOSING\n");
    }

    return 0;
}