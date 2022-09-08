#ifndef __TIC_TAC_TOE_PLAYER__
#define __TIC_TAC_TOE_PLAYER__

#include <iostream>

#ifndef __TIC_TAC_TOE__
#include "TicTacToe.h"
#endif

class TicTacToePlayer {
public:
    TicTacToePlayer(int stone) : stone(stone) {}
    int get_stone();
    void play(TicTacToe *game);

private:
    int stone;

    bool in_range(int i, int j);
};

#endif