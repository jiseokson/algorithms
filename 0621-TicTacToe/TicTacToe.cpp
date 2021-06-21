#include "TicTacToe.h"

bool TicTacToe::filled(int i, int j) { return board[i][j] != 0; }

void TicTacToe::put(int stone, int i, int j) { board[i][j] = stone; }

int TicTacToe::start() {
    print_board();
    while (!judge(other_player())) {
        current_player().play(this);
        print_board();
        turn_end();
    }
    return other_player().get_stone();
}

TicTacToePlayer& TicTacToe::current_player() { return turn % 2 == 0? px: po; }

TicTacToePlayer& TicTacToe::other_player() { return turn % 2 == 0? po: px; }

void TicTacToe::print_board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << board[i][j];
        std::cout << '\n';
    }
}

bool TicTacToe::judge(TicTacToePlayer& player) {
    int stone = player.get_stone();
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == stone && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == stone && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (
        board[0][0] == stone && board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
        board[0][2] == stone && board[0][2] == board[1][1] && board[1][1] == board[2][0]
    ) return true;
}

void TicTacToe::turn_end() { ++turn; }