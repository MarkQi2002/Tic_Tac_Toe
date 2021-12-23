#include "board.h"

// Constructors
Board::Board(){
    for (int i = 0; i < large_board_size; i++){
        for (int j = 0; j < large_board_size; j++){
            largeBoard[i][j] = Empty;
        }
    }

    for (int i = 0; i < small_board_size; i++){
        for (int j = 0; j < small_board_size; j++){
            smallBoard[i][j] = Empty;
        }
    }
}

// Mutators
void Board::setLargeBoard(int row, int col, char player){
    largeBoard[row][col] = player;
}

void Board::setSmallBoard(int row, int col, char player){
    smallBoard[row][col] = player;
}

// Accessors
char Board::getLargeBoard(int row, int col){
    return largeBoard[row][col];
}

char Board::getSmallBoard(int row, int col){
    return smallBoard[row][col];
}

// Utility Functions
void Board::drawSmallBoard(){
    for (int i = 0; i < small_board_size; i++){
        for (int j = 0; j < small_board_size; j++){
            cout << smallBoard[i][j];
        }
        cout << endl;
    }
}

void Board::drawLargeBoard(){
    for (int i = 0; i < large_board_size; i++){
        for (int j = 0; j < large_board_size; j++){
            if (j == 2 || j == 5) cout << largeBoard[i][j] << "||";
            else if (j == 8) cout << largeBoard[i][j] << endl;
            else cout << largeBoard[i][j];
        }
        if (i == 2 || i == 5) cout << "-------------" << endl;
    }
}

void Board::helperWin(int row, int col){
    for (int i = 0; i < small_board_size; i++){
        if (largeBoard[row + i][col] == Noughts && largeBoard[row + i][col + 1] == Noughts && largeBoard[row + i][col + 2] == Noughts)
            smallBoard[row / 3][col / 3] = Noughts;
        else if (largeBoard[row + i][col] == Crosses && largeBoard[row + i][col + 1] == Crosses && largeBoard[row + i][col + 2] == Crosses)
            smallBoard[row / 3][col / 3] = Crosses;
    }

    for (int i = 0; i < small_board_size; i++){
        if (largeBoard[row][col + i] == Noughts && largeBoard[row + 1][col + i] == Noughts && largeBoard[row + 2][col + i] == Noughts)
            smallBoard[row / 3][col / 3] = Noughts;
        else if (largeBoard[row][col + i] == Crosses && largeBoard[row + 1][col + i] == Crosses && largeBoard[row + 2][col + i] == Crosses)
            smallBoard[row / 3][col / 3] = Crosses;
    }

    if (largeBoard[row][col] == Noughts && largeBoard[row + 1][col + 1] == Noughts && largeBoard[row + 2][col + 2] == Noughts) 
        smallBoard[row / 3][col / 3] = Noughts;
    else if (largeBoard[row][col] == Crosses && largeBoard[row + 1][col + 1] == Crosses && largeBoard[row + 2][col + 2] == Crosses) 
        smallBoard[row / 3][col / 3] = Crosses;

    if (largeBoard[row][col + 2] == Noughts && largeBoard[row + 1][col + 1] == Noughts && largeBoard[row + 2][col] == Noughts) 
        smallBoard[row / 3][col / 3] = Noughts;
    else if (largeBoard[row][col + 2] == Crosses && largeBoard[row + 1][col + 1] == Crosses && largeBoard[row + 2][col] == Crosses) 
        smallBoard[row / 3][col / 3] = Crosses;
}

void Board::checkWin(){
    for (int i = 0; i < large_board_size; i ++){
        helperWin(0 + 3 * (i / 3), 0 + 3 * (i % 3));
    }
}

void Board::win(bool & gameOver, int & countFirstPlayerWin, int & countSecondPlayerWin, int & countDraw){
    for (int i = 0; i < small_board_size; i++){
        if (smallBoard[i][0] == Noughts && smallBoard[i][1] == Noughts && smallBoard[i][2] == Noughts) {cout << "\033[35mGame Over " << Noughts << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countSecondPlayerWin++; return;}
        else if (smallBoard[i][0] == Crosses && smallBoard[i][1] == Crosses && smallBoard[i][2] == Crosses) {cout << "\033[36mGame Over " << Crosses << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countFirstPlayerWin++; return;}
    }

    for (int i = 0; i < small_board_size; i++){
        if (smallBoard[0][i] == Noughts && smallBoard[1][i] == Noughts && smallBoard[2][i] == Noughts) {cout << "\033[35mGame Over " << Noughts << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countSecondPlayerWin++; return;}
        else if (smallBoard[0][i] == Crosses && smallBoard[1][i] == Crosses && smallBoard[2][i] == Crosses) {cout << "\033[36mGame Over " << Crosses << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countFirstPlayerWin++; return;}
    }

    if (smallBoard[0][0] == Noughts && smallBoard[1][1] == Noughts && smallBoard[2][2] == Noughts) {cout << "\033[35mGame Over " << Noughts << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countSecondPlayerWin++; return;}
    else if (smallBoard[0][0] == Crosses && smallBoard[1][1] == Crosses && smallBoard[2][2] == Crosses) {cout << "\033[36mGame Over " << Crosses << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countFirstPlayerWin++; return;}

    if (smallBoard[0][2] == Noughts && smallBoard[1][1] == Noughts && smallBoard[2][0] == Noughts) {cout << "\033[35mGame Over " << Noughts << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countSecondPlayerWin++; return;}
    else if (smallBoard[0][2] == Crosses && smallBoard[1][1] == Crosses && smallBoard[2][0] == Crosses) {cout << "\033[36mGame Over " << Crosses << " Wins\033[0m" << endl; gameOver = true; drawLargeBoard(); countFirstPlayerWin++; return;}

    // Identifying Draws
    int count = 0;
    for (int i = 0; i < large_board_size; i++){
        if (smallBoard[i / 3][i % 3] != Empty) count = count + 1;
    }
    if (count == 9) {cout << "\033[32mGAME DRAW!!!\033[0m" << endl; gameOver = true; drawLargeBoard(); countDraw++; return;}
}

void Board::checkFull(int row, int col){
    int count = 0;
    for (int i = 0; i < large_board_size; i++){
        if (largeBoard[row + (i / 3)][col + (i % 3)] != Empty) count++;
    }
    if (count == 9) {smallBoard[row/3][col/3] = 'F';}
}