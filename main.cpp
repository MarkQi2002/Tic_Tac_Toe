#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

#include "globals.h"
#include "board.h"

// Main Function
int main(){
    // Variable Declearation
    Board largeBoard;
    char currentPlayer = Crosses;
    int currentSection = 9;
    bool gameOver = false;

    // For Analyzing Wining Probability
    int countFirstPlayerWin = 0;
    int countSecondPlayerWin = 0;
    int countDraw = 0;
    
    // For Assigning Players
    int firstPlayer = -1;
    int secondPlayer = -1;

    // For AI (Setting Random Generator Based On Current Time)
    srand((unsigned) time(0));

    // Set Players 1 (FirstHand)
    while (firstPlayer == -1){
        string playerSelectOne;
        cout << "\033[35mPlease Choose Player One (Crosses), Human (0), AI1 (1), AI2 (2), AI3 (3), AI4 (4), AI5 (5), AI6 (6): \033[0m";
        getline(cin, playerSelectOne);
        if (playerSelectOne != "0" && playerSelectOne != "1" && playerSelectOne != "2" && playerSelectOne != "3" && playerSelectOne != "4" && playerSelectOne != "5" && playerSelectOne != "6") cout << "\033[31mInvalid Input\033[0m" << endl;
        else firstPlayer = stoi(playerSelectOne);
    }

    // Set Player 2 (SecondHand)
    while (secondPlayer == -1){
        string playerSelectTwo;
        cout << "\033[35mPlease Choose Player Two (Noughts), Human (0), AI1 (1), AI2 (2), AI3 (3), AI4 (4), AI5 (5), AI6 (6): \033[0m";
        getline(cin, playerSelectTwo);
        if (playerSelectTwo != "0" && playerSelectTwo != "1" && playerSelectTwo != "2" && playerSelectTwo != "3" && playerSelectTwo != "4" && playerSelectTwo != "5" && playerSelectTwo != "6") cout << "\033[31mInvalid Input\033[0m" << endl;
        else secondPlayer = stoi(playerSelectTwo);
    }
    
    // Use Below Part Only Without For Loop
    // Cheats for Human Player One
    /*if (firstPlayer == Player) {
        string cheatInput;
        cout << "The Cheat Will Grant Player Center Section at Beginning of the Game!" << endl;
        cout << "Do you want to enable cheat for Player One (Human Player) (Y/N): ";
        getline(cin, cheatInput);
        while (cheatInput != "Y"  && cheatInput != "N"){
            cout << "\033[31mInvalid Input\033[0m" << endl;
            getline(cin, cheatInput);
        }
            
        if (cheatInput == "Y"){
            cout << "\033[31mCheat Enabled For Player One!\033[0m" << endl;
            largeBoard.setSmallBoard(1, 1, Crosses);
            for (int i = 0; i < large_board_size; i++){
                largeBoard.setLargeBoard(3 + (i / 3), 3 + (i % 3), Crosses);
            }
            currentSection = 10;
        }
    } 

    // Cheats for Human Player Two
    if (secondPlayer == Player) {
        string cheatInput;
        cout << "The Cheat Will Grant Player Center Section at Beginning of the Game!" << endl;
        cout << "Do you want to enable cheat for Player Two (Human Player) (Y/N): ";
        getline(cin, cheatInput);
        while (cheatInput != "Y"  && cheatInput != "N"){
            cout << "\033[31mInvalid Input\033[0m" << endl;
            getline(cin, cheatInput);
        }
        
        if (cheatInput == "Y"){
            cout << "\033[31mCheat Enabled For Player One!\033[0m" << endl;
            largeBoard.setSmallBoard(1, 1, Noughts);
            for (int i = 0; i < large_board_size; i++){
                largeBoard.setLargeBoard(3 + (i / 3), 3 + (i % 3), Noughts);
            }
            currentSection = 10;
        }
    } */

    // This For Loop Will Run the Game Automatically For 1000 Times (Testing Purposes ONLY)
    for (int z = 0; z < 1000; z++) {
        // Reinitialize the Variables
        Board largeBoard;
        char currentPlayer = Crosses;
        int currentSection = 9;
        bool gameOver = false;

        // Cheats for Human Player One
        if (firstPlayer == Player) {
            string cheatInput;
            cout << "The Cheat Will Grant Player Center Section at Beginning of the Game!" << endl;
            cout << "Do you want to enable cheat for Player One (Human Player) (Y/N): ";
            getline(cin, cheatInput);
            while (cheatInput != "Y"  && cheatInput != "N"){
                cout << "\033[31mInvalid Input\033[0m" << endl;
                getline(cin, cheatInput);
            }
            
            if (cheatInput == "Y"){
                cout << "\033[31mCheat Enabled For Player One!\033[0m" << endl;
                largeBoard.setSmallBoard(1, 1, Crosses);
                for (int i = 0; i < large_board_size; i++){
                    largeBoard.setLargeBoard(3 + (i / 3), 3 + (i % 3), Crosses);
                }
                currentSection = 10;
            }
        }

        // Cheats for Human Player Two
        if (secondPlayer == Player) {
            string cheatInput;
            cout << "The Cheat Will Grant Player Center Section at Beginning of the Game!" << endl;
            cout << "Do you want to enable cheat for Player Two (Human Player) (Y/N): ";
            getline(cin, cheatInput);
            while (cheatInput != "Y"  && cheatInput != "N"){
                cout << "\033[31mInvalid Input\033[0m" << endl;
                getline(cin, cheatInput);
            }
            
            if (cheatInput == "Y"){
                cout << "\033[31mCheat Enabled For Player One!\033[0m" << endl;
                largeBoard.setSmallBoard(1, 1, Noughts);
                for (int i = 0; i < large_board_size; i++){
                    largeBoard.setLargeBoard(3 + (i / 3), 3 + (i % 3), Noughts);
                }
                currentSection = 10;
            }
        }

        // Indicator of New Game
        cout << "\033[35mNew Game Starts\033[0m" << endl;
    
    // The Main Game Part
    while (!cin.eof() && !gameOver){
        // Varialbe Declearation
        bool valid = true;
        int temp_Section;
        int temp_Row;
        int temp_Col;
        string line;

        // Receiving and Processing User Inputs (For Human Player) (By Mark)
        if ((currentPlayer == Crosses && firstPlayer == 0) || (currentPlayer == Noughts && secondPlayer == 0)){
            largeBoard.drawLargeBoard();
            if (currentSection == 9) cout << "Any Section Can Be Choose" << endl;
            else if (currentSection == 10) cout << "Any Section Can Be Choose Except Section 5" << endl;
            else cout << "You Are Only Allowed to Choose Section " << currentSection + 1 << endl;
            cout << "Please Input Position, Section (1-9), Row (1-3), Col (1-3), Each Separated with a Space: ";
            getline(cin, line);
        }

        // Receiving and Processing AI Inputs (For AI1) (By Mark)
        if ((currentPlayer == Crosses && firstPlayer == 1) || (currentPlayer == Noughts && secondPlayer == 1)){
            if (currentSection == 9) line += to_string(rand() % 9 + 1);
            else if (currentSection == 10) line += to_string(1);
            else line += to_string(currentSection + 1);
            line += ' ';
            line += to_string(rand() % 3 + 1);
            line += ' ';
            line += to_string(rand() % 3 + 1);
        }
        
        // Receiving and Processing AI Inputs (For AI2) (By Mark)
        if ((currentPlayer == Crosses && firstPlayer == 2) || (currentPlayer == Noughts && secondPlayer == 2)){
            // Variable Declearation
            int AI_Section;

            // For Analyzing Which Section To Place
            if (currentSection == 9 && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
            else if (currentSection == 9 && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
            else if (currentSection == 9 && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
            else if (currentSection == 9 && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
            else if (currentSection == 9 && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
            else if (currentSection == 9 && largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
            else if (currentSection == 9 && largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
            else if (currentSection == 9 && largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
            else if (currentSection == 9 && largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
            else if (currentSection == 10) AI_Section = 1;
            else AI_Section = currentSection + 1;
            line += to_string(AI_Section);
            line += ' ';
            
            // Variable Decleration
            int AI_Row = ((AI_Section - 1) / 3) * 3;
            int AI_Col = ((AI_Section - 1) % 3) * 3;

            // For Analyzing Which Row And Col To Place
            if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
            else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
            else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
            else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
            else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
            else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
            else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
            else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
            else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
        }

        //Receiving and Processing AI Inputs (For AI3) (By Robert)
        if ((currentPlayer == Crosses && firstPlayer == 3) || (currentPlayer == Noughts && secondPlayer == 3)){
            // Empty For Now
        }

        //Receiving and Processing AI Inputs (For AI4) (By Robert)
        if ((currentPlayer == Crosses && firstPlayer == 4) || (currentPlayer == Noughts && secondPlayer == 4)){
            // Empty For Now
        }

        //Receiving and Processing AI Inputs (For AI5) (By Mark)
        if ((currentPlayer == Crosses && firstPlayer == 5) || (currentPlayer == Noughts && secondPlayer == 5)){
            // Variable Decleration
            int AI_Section;
            int AI_Section_Crosses_Analysis[9];
            int AI_Section_Noughts_Analysis[9];

            // Counting Number of Crosses and Noughts in Each Section
            for (int i = 0; i < large_board_size; i++){
                int countCrosses = 0;
                int countNoughts = 0;
                for (int j = 0; j < large_board_size; j++){
                    if (largeBoard.getLargeBoard((i / 3) * 3 + (j / 3), (i % 3) * 3 + (j % 3)) == Crosses) countCrosses++;
                    else if (largeBoard.getLargeBoard((i / 3) * 3 + (j / 3), (i % 3) * 3 + (j % 3)) == Noughts) countNoughts++;
                }
                AI_Section_Crosses_Analysis[i] = countCrosses;
                AI_Section_Noughts_Analysis[i] = countNoughts;
            }

            // For Analyzing Which Section To Place
            if (currentPlayer == Crosses && currentSection == 9){
                if (largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(0, 0) == Empty && AI_Section_Crosses_Analysis[0] >= AI_Section_Noughts_Analysis[0] && AI_Section_Crosses_Analysis[0] >= AI_Section_Crosses_Analysis[2] && AI_Section_Crosses_Analysis[0] >= AI_Section_Crosses_Analysis[6] && AI_Section_Crosses_Analysis[0] >= AI_Section_Crosses_Analysis[8]) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty && AI_Section_Crosses_Analysis[8] >= AI_Section_Noughts_Analysis[8] && AI_Section_Crosses_Analysis[8] >= AI_Section_Crosses_Analysis[0] && AI_Section_Crosses_Analysis[8] >= AI_Section_Crosses_Analysis[2] && AI_Section_Crosses_Analysis[8] >= AI_Section_Crosses_Analysis[6]) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty && AI_Section_Crosses_Analysis[2] >= AI_Section_Noughts_Analysis[2] && AI_Section_Crosses_Analysis[2] >= AI_Section_Crosses_Analysis[0] && AI_Section_Crosses_Analysis[2] >= AI_Section_Crosses_Analysis[6] && AI_Section_Crosses_Analysis[2] >= AI_Section_Crosses_Analysis[8]) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty && AI_Section_Crosses_Analysis[6] >= AI_Section_Noughts_Analysis[6] && AI_Section_Crosses_Analysis[6] >= AI_Section_Crosses_Analysis[0] && AI_Section_Crosses_Analysis[6] >= AI_Section_Crosses_Analysis[2] && AI_Section_Crosses_Analysis[6] >= AI_Section_Crosses_Analysis[8]) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty && AI_Section_Crosses_Analysis[1] >= AI_Section_Noughts_Analysis[1] && AI_Section_Crosses_Analysis[1] >= AI_Section_Crosses_Analysis[3] && AI_Section_Crosses_Analysis[1] >= AI_Section_Crosses_Analysis[5] && AI_Section_Crosses_Analysis[1] >= AI_Section_Crosses_Analysis[7]) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty && AI_Section_Crosses_Analysis[7] >= AI_Section_Noughts_Analysis[7] && AI_Section_Crosses_Analysis[7] >= AI_Section_Crosses_Analysis[1] && AI_Section_Crosses_Analysis[7] >= AI_Section_Crosses_Analysis[3] && AI_Section_Crosses_Analysis[7] >= AI_Section_Crosses_Analysis[5]) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty && AI_Section_Crosses_Analysis[3] >= AI_Section_Noughts_Analysis[3] && AI_Section_Crosses_Analysis[3] >= AI_Section_Crosses_Analysis[1] && AI_Section_Crosses_Analysis[3] >= AI_Section_Crosses_Analysis[5] && AI_Section_Crosses_Analysis[3] >= AI_Section_Crosses_Analysis[7]) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty && AI_Section_Crosses_Analysis[5] >= AI_Section_Noughts_Analysis[5] && AI_Section_Crosses_Analysis[5] >= AI_Section_Crosses_Analysis[1] && AI_Section_Crosses_Analysis[5] >= AI_Section_Crosses_Analysis[3] && AI_Section_Crosses_Analysis[5] >= AI_Section_Crosses_Analysis[7]) AI_Section = 6;
                else if (largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
            }
            else if (currentPlayer == Noughts && currentSection == 9){
                if (largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(0, 0) == Empty && AI_Section_Noughts_Analysis[0] >= AI_Section_Crosses_Analysis[0] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[8]) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty && AI_Section_Noughts_Analysis[8] >= AI_Section_Crosses_Analysis[8] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[6]) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty && AI_Section_Noughts_Analysis[2] >= AI_Section_Crosses_Analysis[2] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[8]) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty && AI_Section_Noughts_Analysis[6] >= AI_Section_Crosses_Analysis[6] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[8]) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty && AI_Section_Noughts_Analysis[1] >= AI_Section_Crosses_Analysis[1] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[7]) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty && AI_Section_Noughts_Analysis[7] >= AI_Section_Crosses_Analysis[7] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[5]) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty && AI_Section_Noughts_Analysis[3] >= AI_Section_Crosses_Analysis[3] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[7]) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty && AI_Section_Noughts_Analysis[5] >= AI_Section_Crosses_Analysis[5] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[7]) AI_Section = 6;
                else if (largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
            }
            else if (currentSection == 10) AI_Section = 1;
            else if (currentSection != 9) AI_Section = currentSection + 1;

            line += to_string(AI_Section);
            line += ' ';

            // Variable Decleration
            int AI_Row = ((AI_Section - 1) / 3) * 3;
            int AI_Col = ((AI_Section - 1) % 3) * 3;

            // For Analyzing Which Row And Col To Place
            if (currentPlayer == Crosses) {

                if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
            }
            else if (currentPlayer == Noughts) {
                if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
            }
        }

        //Receiving and Processing AI Inputs (For AI6) (By Mark)
        if ((currentPlayer == Crosses && firstPlayer == 6) || (currentPlayer == Noughts && secondPlayer == 6)){
            // Variable Decleration
            int AI_Section;
            int AI_Section_Crosses_Analysis[9];
            int AI_Section_Noughts_Analysis[9];

            // Counting Number of Crosses and Noughts in Each Section
            for (int i = 0; i < large_board_size; i++){
                int countCrosses = 0;
                int countNoughts = 0;
                for (int j = 0; j < large_board_size; j++){
                    if (largeBoard.getLargeBoard((i / 3) * 3 + (j / 3), (i % 3) * 3 + (j % 3)) == Crosses) countCrosses++;
                    else if (largeBoard.getLargeBoard((i / 3) * 3 + (j / 3), (i % 3) * 3 + (j % 3)) == Noughts) countNoughts++;
                }
                AI_Section_Crosses_Analysis[i] = countCrosses;
                AI_Section_Noughts_Analysis[i] = countNoughts;
            }

            // For Analyzing Which Section To Place
            if (currentPlayer == Crosses && currentSection == 9){
                if (largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                // Analyzing Opponent Moves
                // Horizontal (Blocking Moves)
                else if (largeBoard.getSmallBoard(0, 0) == Noughts && largeBoard.getSmallBoard(0, 1) == Noughts && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
                else if (largeBoard.getSmallBoard(0, 0) == Noughts && largeBoard.getSmallBoard(0, 2) == Noughts && largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(0, 1) == Noughts && largeBoard.getSmallBoard(0, 2) == Noughts && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(1, 0) == Noughts && largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
                else if (largeBoard.getSmallBoard(1, 0) == Noughts && largeBoard.getSmallBoard(1, 2) == Noughts && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(1, 2) == Noughts && largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(2, 0) == Noughts && largeBoard.getSmallBoard(2, 1) == Noughts && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(2, 0) == Noughts && largeBoard.getSmallBoard(2, 2) == Noughts && largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(2, 1) == Noughts && largeBoard.getSmallBoard(2, 2) == Noughts && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;

                // Vertical (Blocking Moves)
                else if (largeBoard.getSmallBoard(0, 0) == Noughts && largeBoard.getSmallBoard(1, 0) == Noughts && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 0) == Noughts && largeBoard.getSmallBoard(2, 0) == Noughts && largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 0) == Noughts && largeBoard.getSmallBoard(2, 0) == Noughts && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(0, 1) == Noughts && largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(0, 1) == Noughts && largeBoard.getSmallBoard(2, 1) == Noughts && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(2, 1) == Noughts && largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(0, 2) == Noughts && largeBoard.getSmallBoard(1, 2) == Noughts && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Noughts && largeBoard.getSmallBoard(2, 2) == Noughts && largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
                else if (largeBoard.getSmallBoard(1, 2) == Noughts && largeBoard.getSmallBoard(2, 2) == Noughts && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;

                // Diagonal (Blocking Moves)
                else if (largeBoard.getSmallBoard(0, 0) == Noughts && largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 0) == Noughts && largeBoard.getSmallBoard(2, 2) == Noughts && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(2, 2) == Noughts && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(0, 2) == Noughts && largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 2) == Noughts && largeBoard.getSmallBoard(2, 0) == Noughts && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Noughts && largeBoard.getSmallBoard(2, 0) == Noughts && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;

                // Go To Section That Has Higher Probability of Wining that Section
                else if (largeBoard.getSmallBoard(0, 0) == Empty && AI_Section_Crosses_Analysis[0] >= AI_Section_Noughts_Analysis[0] && AI_Section_Crosses_Analysis[0] >= AI_Section_Crosses_Analysis[2] && AI_Section_Crosses_Analysis[0] >= AI_Section_Crosses_Analysis[6] && AI_Section_Crosses_Analysis[0] >= AI_Section_Crosses_Analysis[8]) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty && AI_Section_Crosses_Analysis[8] >= AI_Section_Noughts_Analysis[8] && AI_Section_Crosses_Analysis[8] >= AI_Section_Crosses_Analysis[0] && AI_Section_Crosses_Analysis[8] >= AI_Section_Crosses_Analysis[2] && AI_Section_Crosses_Analysis[8] >= AI_Section_Crosses_Analysis[6]) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty && AI_Section_Crosses_Analysis[2] >= AI_Section_Noughts_Analysis[2] && AI_Section_Crosses_Analysis[2] >= AI_Section_Crosses_Analysis[0] && AI_Section_Crosses_Analysis[2] >= AI_Section_Crosses_Analysis[6] && AI_Section_Crosses_Analysis[2] >= AI_Section_Crosses_Analysis[8]) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty && AI_Section_Crosses_Analysis[6] >= AI_Section_Noughts_Analysis[6] && AI_Section_Crosses_Analysis[6] >= AI_Section_Crosses_Analysis[0] && AI_Section_Crosses_Analysis[6] >= AI_Section_Crosses_Analysis[2] && AI_Section_Crosses_Analysis[6] >= AI_Section_Crosses_Analysis[8]) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty && AI_Section_Crosses_Analysis[1] >= AI_Section_Noughts_Analysis[1] && AI_Section_Crosses_Analysis[1] >= AI_Section_Crosses_Analysis[3] && AI_Section_Crosses_Analysis[1] >= AI_Section_Crosses_Analysis[5] && AI_Section_Crosses_Analysis[1] >= AI_Section_Crosses_Analysis[7]) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty && AI_Section_Crosses_Analysis[7] >= AI_Section_Noughts_Analysis[7] && AI_Section_Crosses_Analysis[7] >= AI_Section_Crosses_Analysis[1] && AI_Section_Crosses_Analysis[7] >= AI_Section_Crosses_Analysis[3] && AI_Section_Crosses_Analysis[7] >= AI_Section_Crosses_Analysis[5]) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty && AI_Section_Crosses_Analysis[3] >= AI_Section_Noughts_Analysis[3] && AI_Section_Crosses_Analysis[3] >= AI_Section_Crosses_Analysis[1] && AI_Section_Crosses_Analysis[3] >= AI_Section_Crosses_Analysis[5] && AI_Section_Crosses_Analysis[3] >= AI_Section_Crosses_Analysis[7]) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty && AI_Section_Crosses_Analysis[5] >= AI_Section_Noughts_Analysis[5] && AI_Section_Crosses_Analysis[5] >= AI_Section_Crosses_Analysis[1] && AI_Section_Crosses_Analysis[5] >= AI_Section_Crosses_Analysis[3] && AI_Section_Crosses_Analysis[5] >= AI_Section_Crosses_Analysis[7]) AI_Section = 6;

                // Go To Section That Has Lower Probability of Wining that Section To Block Opponents
                else if (largeBoard.getSmallBoard(0, 0) == Empty && AI_Section_Noughts_Analysis[0] >= AI_Section_Crosses_Analysis[0] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[8]) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty && AI_Section_Noughts_Analysis[8] >= AI_Section_Crosses_Analysis[8] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[6]) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty && AI_Section_Noughts_Analysis[2] >= AI_Section_Crosses_Analysis[2] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[8]) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty && AI_Section_Noughts_Analysis[6] >= AI_Section_Crosses_Analysis[6] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[8]) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty && AI_Section_Noughts_Analysis[1] >= AI_Section_Crosses_Analysis[1] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[7]) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty && AI_Section_Noughts_Analysis[7] >= AI_Section_Crosses_Analysis[7] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[5]) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty && AI_Section_Noughts_Analysis[3] >= AI_Section_Crosses_Analysis[3] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[7]) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty && AI_Section_Noughts_Analysis[5] >= AI_Section_Crosses_Analysis[5] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[7]) AI_Section = 6;
                
                // Backup Placement
                else if (largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
            }
            else if (currentPlayer == Noughts && currentSection == 9){
                if (largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                // Analyzing Opponent Moves
                // Horizontal (Blocking Moves)
                else if (largeBoard.getSmallBoard(0, 0) == Crosses && largeBoard.getSmallBoard(0, 1) == Crosses && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
                else if (largeBoard.getSmallBoard(0, 0) == Crosses && largeBoard.getSmallBoard(0, 2) == Crosses && largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(0, 1) == Crosses && largeBoard.getSmallBoard(0, 2) == Crosses && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(1, 0) == Crosses && largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
                else if (largeBoard.getSmallBoard(1, 0) == Crosses && largeBoard.getSmallBoard(1, 2) == Crosses && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(1, 2) == Crosses && largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(2, 0) == Crosses && largeBoard.getSmallBoard(2, 1) == Crosses && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(2, 0) == Crosses && largeBoard.getSmallBoard(2, 2) == Crosses && largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(2, 1) == Crosses && largeBoard.getSmallBoard(2, 2) == Crosses && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;

                // Vertical (Blocking Moves)
                else if (largeBoard.getSmallBoard(0, 0) == Crosses && largeBoard.getSmallBoard(1, 0) == Crosses && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 0) == Crosses && largeBoard.getSmallBoard(2, 0) == Crosses && largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 0) == Crosses && largeBoard.getSmallBoard(2, 0) == Crosses && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(0, 1) == Crosses && largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(0, 1) == Crosses && largeBoard.getSmallBoard(2, 1) == Crosses && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(2, 1) == Crosses && largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(0, 2) == Crosses && largeBoard.getSmallBoard(1, 2) == Crosses && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Crosses && largeBoard.getSmallBoard(2, 2) == Crosses && largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
                else if (largeBoard.getSmallBoard(1, 2) == Crosses && largeBoard.getSmallBoard(2, 2) == Crosses && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;

                // Diagonal (Blocking Moves)
                else if (largeBoard.getSmallBoard(0, 0) == Crosses && largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 0) == Crosses && largeBoard.getSmallBoard(2, 2) == Crosses && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(2, 2) == Crosses && largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(0, 2) == Crosses && largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 2) == Crosses && largeBoard.getSmallBoard(2, 0) == Crosses && largeBoard.getSmallBoard(1, 1) == Empty) AI_Section = 5;
                else if (largeBoard.getSmallBoard(1, 1) == Crosses && largeBoard.getSmallBoard(2, 0) == Crosses && largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;

                // Go To Section That Has Higher Probability of Wining that Section
                else if (largeBoard.getSmallBoard(0, 0) == Empty && AI_Section_Noughts_Analysis[0] >= AI_Section_Crosses_Analysis[0] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[8]) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty && AI_Section_Noughts_Analysis[8] >= AI_Section_Crosses_Analysis[8] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[6]) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty && AI_Section_Noughts_Analysis[2] >= AI_Section_Crosses_Analysis[2] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[8]) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty && AI_Section_Noughts_Analysis[6] >= AI_Section_Crosses_Analysis[6] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[8]) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty && AI_Section_Noughts_Analysis[1] >= AI_Section_Crosses_Analysis[1] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[7]) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty && AI_Section_Noughts_Analysis[7] >= AI_Section_Crosses_Analysis[7] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[5]) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty && AI_Section_Noughts_Analysis[3] >= AI_Section_Crosses_Analysis[3] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[7]) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty && AI_Section_Noughts_Analysis[5] >= AI_Section_Crosses_Analysis[5] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[7]) AI_Section = 6;
                
                // Go To Section That Has Lower Probability of Wining that Section To Block Opponents
                else if (largeBoard.getSmallBoard(0, 0) == Empty && AI_Section_Noughts_Analysis[0] >= AI_Section_Crosses_Analysis[0] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[0] >= AI_Section_Noughts_Analysis[8]) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty && AI_Section_Noughts_Analysis[8] >= AI_Section_Crosses_Analysis[8] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[8] >= AI_Section_Noughts_Analysis[6]) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty && AI_Section_Noughts_Analysis[2] >= AI_Section_Crosses_Analysis[2] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[6] && AI_Section_Noughts_Analysis[2] >= AI_Section_Noughts_Analysis[8]) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty && AI_Section_Noughts_Analysis[6] >= AI_Section_Crosses_Analysis[6] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[0] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[2] && AI_Section_Noughts_Analysis[6] >= AI_Section_Noughts_Analysis[8]) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty && AI_Section_Noughts_Analysis[1] >= AI_Section_Crosses_Analysis[1] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[1] >= AI_Section_Noughts_Analysis[7]) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty && AI_Section_Noughts_Analysis[7] >= AI_Section_Crosses_Analysis[7] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[7] >= AI_Section_Noughts_Analysis[5]) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty && AI_Section_Noughts_Analysis[3] >= AI_Section_Crosses_Analysis[3] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[5] && AI_Section_Noughts_Analysis[3] >= AI_Section_Noughts_Analysis[7]) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty && AI_Section_Noughts_Analysis[5] >= AI_Section_Crosses_Analysis[5] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[1] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[3] && AI_Section_Noughts_Analysis[5] >= AI_Section_Noughts_Analysis[7]) AI_Section = 6;

                // Backup Placement
                else if (largeBoard.getSmallBoard(0, 0) == Empty) AI_Section = 1;
                else if (largeBoard.getSmallBoard(2, 2) == Empty) AI_Section = 9;
                else if (largeBoard.getSmallBoard(0, 2) == Empty) AI_Section = 3;
                else if (largeBoard.getSmallBoard(2, 0) == Empty) AI_Section = 7;
                else if (largeBoard.getSmallBoard(0, 1) == Empty) AI_Section = 2;
                else if (largeBoard.getSmallBoard(2, 1) == Empty) AI_Section = 8;
                else if (largeBoard.getSmallBoard(1, 0) == Empty) AI_Section = 4;
                else if (largeBoard.getSmallBoard(1, 2) == Empty) AI_Section = 6;
            }
            else if (currentSection == 10) AI_Section = 1;
            else if (currentSection != 9) AI_Section = currentSection + 1;

            line += to_string(AI_Section);
            line += ' ';
            
            // Variable Decleration
            int AI_Row = ((AI_Section - 1) / 3) * 3;
            int AI_Col = ((AI_Section - 1) % 3) * 3;

            // For Analyzing Which Row And Col To Place
            if (currentPlayer == Crosses) {
                if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);} // Center Piece
                // Analyzing Opponent Moves
                // Diagonal (Blocking Moves)
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}

                // Horizontal (Blocking Moves)
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}

                // Verital (Blocking Moves)
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}

                // Non Blocking Move But in Sequence
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
            }
            else if (currentPlayer == Noughts) {
                if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                // Analyzing Opponent Moves
                 // Diagonal (Blocking Moves)
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}

                // Horizontal (Blocking Moves)
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}

                // Verital (Blocking Moves)
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Empty) {line += to_string(2); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Crosses && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}

                // Non Blocking Move But in Sequence
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Empty) {line += to_string(1); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Empty) {line += to_string(3); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Empty) {line += to_string(1); line += ' '; line += to_string(3);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Empty) {line += to_string(3); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 2) == Noughts && largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row, AI_Col + 1) == Empty) {line += to_string(1); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 2, AI_Col + 1) == Empty) {line += to_string(3); line += ' '; line += to_string(2);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col) == Empty) {line += to_string(2); line += ' '; line += to_string(1);}
                else if (largeBoard.getLargeBoard(AI_Row + 1, AI_Col + 2) == Empty) {line += to_string(2); line += ' '; line += to_string(3);}
            }
        }

        // Convert To LineStream
        stringstream lineStream (line);

        // Verifying Input
        if (lineStream >> temp_Section){
            if (temp_Section < 1 || temp_Section > 9 || ((currentSection != 9 && currentSection != 10) && temp_Section - 1 != currentSection)) {valid = false; cout << "\033[31mIncorrect Section, \033[0m";}
        }
        else valid = false;

        if (lineStream >> temp_Row){
            if (temp_Row < 1 || temp_Row > 3) valid = false;
        }
        else valid = false;

        if (lineStream >> temp_Col){
            if (temp_Col < 1 || temp_Row > 3) valid = false;
        }
        else valid = false;
        
        if (!valid) {cout << "\033[31mInvalid Input\033[0m" << endl;}

        // Modifying the Board if Input is Valid
        if (valid && !gameOver){
            currentSection = (temp_Row - 1) * 3 + temp_Col - 1;
            temp_Section = temp_Section - 1;
            temp_Row = temp_Row + 3 * (temp_Section / 3) - 1;
            temp_Col = temp_Col + 3 * (temp_Section % 3) - 1;

            if (largeBoard.getSmallBoard(currentSection / 3, currentSection % 3) != Empty) currentSection = 9;

            // Check if the Location is Empty or Not
            if (largeBoard.getLargeBoard(temp_Row, temp_Col) == Empty && largeBoard.getSmallBoard(temp_Section / 3, temp_Section % 3) == Empty){
                // Set the Board and Check Game Conditions
                largeBoard.setLargeBoard(temp_Row, temp_Col, currentPlayer);
                largeBoard.checkWin();
                largeBoard.checkFull((temp_Section / 3) * 3, (temp_Section % 3) * 3);
                largeBoard.win(gameOver, countFirstPlayerWin, countSecondPlayerWin, countDraw);

                if (largeBoard.getSmallBoard(temp_Section / 3, temp_Section % 3) != Empty) currentSection = 9;

                // Switching Role at the End
                if (currentPlayer == Noughts) currentPlayer = Crosses;
                else currentPlayer = Noughts;
            }
        }
    }

    // For Human Player If They Want To Exit the Game
    if (firstPlayer == Player || secondPlayer == Player) {
        string exitGame;
        cout << "\033[33mDo you want to exit game (Y/N): ";
        getline(cin, exitGame);
        while (exitGame != "Y"  && exitGame != "N"){
            cout << "\033[31mInvalid Input\033[0m" << endl;
            getline(cin, exitGame);
        }
            
        if (exitGame == "Y"){
            cout << "\033[31mTHE END!!!\033[0m" << endl;
            break;
        }
    }

    } // End of For Loop
    // For Calculating Percentage Win Rate
    cout << "\033[33m" << countFirstPlayerWin << "  " << countSecondPlayerWin << "  " << countDraw << "\033[0m" << endl;
    float winRateForFirstPlayer = (float) countFirstPlayerWin / (float) (countFirstPlayerWin + countSecondPlayerWin);
    float winRateForSecondPlayer = (float) countSecondPlayerWin / (float) (countFirstPlayerWin + countSecondPlayerWin);
    
    // Result for First Player
    cout << "\033[32mFirstHand Player, ";
    if (firstPlayer == 0) cout << "Human Player";
    else if (firstPlayer == 1) cout << "AI1";
    else if (firstPlayer == 2) cout << "AI2";
    else if (firstPlayer == 3) cout << "AI3";
    else if (firstPlayer == 4) cout << "AI4";
    else if (firstPlayer == 5) cout << "AI5";
    else if (firstPlayer == 6) cout << "AI6";
    cout << ", Win Rate (Excluding Draws): " << winRateForFirstPlayer << "\033[0m" << endl;

    // Result for Second Player
    cout << "\033[32mSecondHand Player, ";
    if (secondPlayer == 0) cout << "Human Player";
    else if (secondPlayer == 1) cout << "AI1";
    else if (secondPlayer == 2) cout << "AI2";
    else if (secondPlayer == 3) cout << "AI3";
    else if (secondPlayer == 4) cout << "AI4";
    else if (secondPlayer == 5) cout << "AI5";
    else if (secondPlayer == 6) cout << "AI6";
    cout << ", Win Rate (Excluding Draws): " << winRateForSecondPlayer << "\033[0m" << endl;

    // Result for Draws
    cout << "\033[36mThere were a total of " << countDraw << " draws\033[0m" << endl;

    // Game Ends Here
    return 0;
}