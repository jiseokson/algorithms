#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi board;

bool valid(int y, int x, int n) {
    for (int i = 0; i < 9; ++i) {
        if (i != y && board[i][x] != 0 && board[i][x] == n) return false;
        if (i != x && board[y][i] != 0 && board[y][i] == n) return false;
        int yb = y / 3 * 3 + i / 3, xb = x / 3 * 3 + i % 3;
        if (!(yb == y && xb == x) && board[yb][xb] != 0 && board[yb][xb] == board[y][x]) return false;
    }
    return true;
}

int solve(int i) {
    for (; i < 81; ++i) {
        int y = i / 9, x = i % 9;
        if (board[y][x]) continue;
        for (int n = 1; n <= 9; ++n) {
            if (!valid(y, x, n)) continue;
            board[y][x] = n;
            if (solve(i)) return true;
            board[y][x] = 0;
        }
        return false;
    }
    return true;
}

void print_board() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void get_input() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
}

int main(void) {
    board = vvi(9, vi(9, 0));
    get_input();
    solve(0);
    print_board();
    return 0;
}