#include <iostream>
#include "TicTacToe.h"
#include "TicTacToePlayer.h"

int main(void) {
    TicTacToe ttt;
    int res = ttt.start();
    std::cout << "Victory of " << (char)res << '\n';
    return 0;
}