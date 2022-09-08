#include "TicTacToePlayer.h"

int TicTacToePlayer::get_stone() { return stone; }

void TicTacToePlayer::play(TicTacToe *game) {
    int i, j;
    std::cout << "Turn of " << (char)stone << ": ";
    std::cin >> i >> j;
    if (!in_range(i, j)) {
        std::cout << i << ", " << j << ": Out of range.\n";
        play(game);
    } else if (game -> filled(i, j)) {
        std::cout << i << ", " << j << ": This place has been already taken by other player.\n";
        play(game);
    } else 
        game -> put(stone, i, j);
}

bool TicTacToePlayer::in_range(int i, int j) { return 0 <= i && i < 3 && 0 <= j && j < 3; }