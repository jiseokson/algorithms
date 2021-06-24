#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int c;
vs board;
vi dp;

// TODO: make blocks
vector<ii> block[2][4] = {
    {
        {{}, {}, {}, {}},
        {{}, {}, {}, {}},
        {{}, {}, {}, {}},
        {{}, {}, {}, {}}
    },
    {
        {{}, {}, {}, {}},
        {{}, {}, {}, {}},
        {{}, {}, {}, {}},
        {{}, {}, {}, {}}
    }
};

int bi() {
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

int can_win() {
    int &res = dp[bi()];
    if (res != -2) return res;

    int next = 2;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int bid = 0; bid < 2; ++bid) {
                for (int t = 0; t < 4; ++t) {

                    bool ok = true;
                    for (ii b: block[bid][t]) { // fill
                        int dr = b.first, dc = b.second;
                        int br = i + dr, bc = j + dc;
                        if (!in_range(br, bc) || board[br][bc] == '#') {
                            ok = false;
                            breal;
                        }
                    }

                    if (ok) next = min(next, can_win());

                    for (ii b: block[bid][t]) { // empty
                        int dr = b.first, dc = b.second;
                        int br = i + dr, bc = j + dc;
                        if (in_range(br, bc)) board[br][bc] = '.';
                    }

                }
            }
        }
    }

    if (next == 2) return res = -1; // 내가 놓을수 있는 블럭이 없으면 패배
    return res = -next;
}

int main(void) {
    cin >> c;

    while (c--) {
        board = vs(5, "     ");
        dp = vi(33554432, -2);
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> board[i][j];
        cout << (can_win() == 1? "WINNING\n": "LOSING\n");
    }

    return 0;
}