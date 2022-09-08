#ifndef __TIC_TAC_TOE__
#define __TIC_TAC_TOE__

#include <iostream>
#include <vector>

#ifndef __TIC_TAC_TOE_PLAYER__
#include "TicTacToePlayer.h"
#endif

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class TicTacToe {
public:
    TicTacToe() : board(3, vi(3, 0)), turn(0), px('x'), po('o') {}
    bool filled(int i, int j);
    void put(int stone, int i, int j);
    int start();

private:
    vvi board;
    int turn;
    TicTacToePlayer px, po;

    TicTacToePlayer& current_player();
    TicTacToePlayer& other_player();
    void print_board();
    bool judge(TicTacToePlayer& player);
    void turn_end();
};

#endif