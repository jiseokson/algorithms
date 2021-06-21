#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi board;
vi dp;

void print_board(int turn, int t, int next) {
    static string tab[] = {
        "",
        "  ",
        "    ",
        "      ",
        "        ",
        "          ",
        "            ",
        "              ",
        "                ",
        "                  "
    };

    for (int i = 0; i < 3; ++i) {
        cout << tab[t];
        for (int j = 0; j < 3; ++j)
            cout << (board[i][j] == 0? '.': (char)board[i][j]);
        cout << '\n';
    }
    cout << tab[t] << "#" << t << ", turn: " << (char)turn << ", res: " << -next << "\n\n";
}

bool judge(int turn) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == turn && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == turn && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (
        board[0][0] == turn && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] == turn && board[0][2] == board[1][1] && board[1][1] == board[2][0]
    ) return true;
}

int bi() {
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ret *= 3;
            if (board[i][j] == 'x') ret += 1;
            else if (board[i][j] == 'o') ret += 2;
        }
    }
    return ret;
}

int can_win(int turn, int t) {
    if (judge('o' + 'x' - turn)) return -1;
    int &ret = dp[bi()];
    if (ret != -2) return ret;

    int next = 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = turn;
                next = min(next, can_win('o' + 'x' - turn, t + 1));
                print_board(turn, t, next);
                board[i][j] = 0;
            }
        }
    }

    if (next == 2 || next == 0) return ret = 0;
    return ret = -next;
}

int main(void) {
    board = vvi(3, vi(3, 0));
    dp = vi(19683, -2);
    int res = can_win('x', 1);
    cout << "x res: " << res << '\n';
    return 0;
}