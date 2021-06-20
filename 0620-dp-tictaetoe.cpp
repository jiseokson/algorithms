#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi dp;

bool judge(vvi &board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] != 0 && board[0][i] == board[0][i] && board[1][i] == board[2][i]) return true;
    }
    if (
        board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]
    ) return true;
}

inline int bi(vvi &board) {
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

inline void print_board(vvi &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << (board[i][j] == 0? '.': (char)board[i][j]);
        }
        cout << '\n';
    }
}

int can_win(vvi &board, int turn) {
    if (judge(board)) return -1;
    int &ret = dp[bi(board)];
    if (ret != -2) return ret;

    int next = 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = turn;
                next = min(next, can_win(board, 'o' + 'x' - turn));
                board[i][j] = 0;
            }
        }
    }

    if (next == 2 || next == 0) return ret = 0;
    return ret = -next;
}

inline int pow(int a, int n) {
    if (n == 0) return 1;
    return a * pow(a, n - 1);
}

int main(void) {
    vvi board(3, vi(3, 0));
    dp = vi(pow(3, 9), -2);
    cout << can_win(board, 'x');
    return 0;
}