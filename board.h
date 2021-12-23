// Pragma Once
#ifndef _board_h
#define _board_h

#include <iostream>
#include "globals.h"
using namespace std;

class Board{
    private:
        char largeBoard[large_board_size][large_board_size];
        char smallBoard[small_board_size][small_board_size];
    public:
        // Constructor
        Board();
        
        // Accessors and Mutators
        void setLargeBoard(int row, int col, char player);
        void setSmallBoard(int row, int col, char player);
        char getLargeBoard(int row, int col);
        char getSmallBoard(int row, int col);
        
        // Utility Functions
        void drawLargeBoard();
        void drawSmallBoard();

        void helperWin(int row, int col);
        void checkWin();
        void win(bool & gameOver, int & countFirstPlayerWin, int & countSecondPlayerWin, int & countDraw);
        
        void checkFull(int row, int col);
};

#endif