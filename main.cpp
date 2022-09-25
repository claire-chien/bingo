//

//  main.cpp

//  bingo

//

//  Created by Claire Chien on 8/31/22.

//



#include <iostream>

#include <string>

#include <cctype>

#include <cstdlib>

#include <ctime>

using namespace std;



bool validBoardInput(string userInput, string playerBoard[5][5]);

void setBoard(string playerBoard[5][5]);

void move(string playerOneBoard[5][5], string playerTwoBoard[5][5]);

void printBoards(string playerOneBoard[5][5], string playerTwoBoard[5][5]);

int checkBingo(string playerOneBoard[5][5], string playerTwoBoard[5][5]);

int checkRows(string playerOneBoard[5][5], string playerTwoBoard[5][5]);

int checkColumns(string playerOneBoard[5][5], string playerTwoBoard[5][5]);

int checkDiagonals(string playerOneBoard[5][5], string playerTwoBoard[5][5]);

bool isGameOver(string playerOneBoard[5][5], string playerTwoBoard[5][5], int round);
 





int main() {

    char playOrQuit;

    bool gameInProgress = true;

    bool validInput = false;

    string playerOneBoard[5][5] = {};

    string playerTwoBoard[5][5] = {};

    int round = 0;


    cout << "Let's play Bingo!" << endl << "Enter (p) to play or (q) to quit: ";

    cin >> playOrQuit;

    cout << endl;


    while (validInput == false) {

        switch (playOrQuit) {

        case 'p':

            validInput = true;

            break;

        case 'q':

            validInput = true;

            cout << "Goodbye!" << endl;

            gameInProgress = false;

            break;

        default:

            cout << "Sorry, that's not a valid option. Please try again: " << endl;
            
            cin >> playOrQuit;

            cout << endl;

        }

    }



    if (gameInProgress) {

        cout << "This is a two-player game. Make sure you have a Player One and a Player Two!" << endl << endl;



        cout << "Player One, please input 24 numbers between 1-40 (no repeats!) Please hit enter or space after each number." << endl;

        setBoard(playerOneBoard);



        cout << "Player Two, please input 24 numbers between 1-40 (no repeats!) Please hit enter after each number." << endl;

        setBoard(playerTwoBoard);

        printBoards(playerOneBoard, playerTwoBoard);


        cout << "Thanks for filling out your Bingo cards! Enter (p) to play and (q) to quit: ";

        cin >> playOrQuit;

        cout << endl;

        validInput = false;

        while (validInput == false) {

            switch (playOrQuit) {

            case 'p':

                validInput = true;

                break;

            case 'q':

                validInput = true;

                cout << "Goodbye!" << endl;

                gameInProgress = false;

                break;

            default:

                cout << "Sorry, that's not a valid option. Please try again: " << endl;
                    
                    ;
                cin >> playOrQuit;
                cout << endl;

            }
        }

    }
    
    while (gameInProgress) {

        move(playerOneBoard, playerTwoBoard);

        printBoards(playerOneBoard, playerTwoBoard);


        round++;

        if (isGameOver(playerOneBoard, playerTwoBoard, round)) {

            gameInProgress = false;

        }

        else {

            cout << endl << "Enter (p) to play the next round or (q) to quit: ";


            validInput = false;
            while (validInput == false) {
                
                cin >> playOrQuit;
                
                switch (playOrQuit) {

                case 'p':

                    validInput = true;

                    break;

                case 'q':

                    validInput = true;

                    cout << "Goodbye!" << endl;

                    gameInProgress = false;

                    break;

                default:

                    cout << "Sorry, that's not a valid option. Please try again: " << endl;

                }
            }

        }

    }

}



bool validBoardInput(string userInput, string playerBoard[5][5]) {

    bool validInput = true;

    if (userInput.size() == 0) {

        validInput = false;

        cout << "You didn't enter anything!";

    }

    else {

        for (int i = 0; i < userInput.size(); i++) {

            if (isdigit(userInput.at(i)) == 0) {

                validInput = false;

                cout << "That's not a number!";
                
                break;

            }

        }

        if (validInput) {

            if (stoi(userInput) >= 1 && stoi(userInput) <= 40) {

                for (int j = 0; j < 5; j++) {

                    for (int k = 0; k < 5; k++) {

                        if (userInput == playerBoard[j][k]) {

                            validInput = false;

                            cout << "You've already used that number!";

                            //cout << "j = " << j << " k = " << k << endl;;

                            //cout << "board[j] = " << j << " board[k] = " << k << endl;

                            break;

                        }

                    }

                }

            }

            else {

                validInput = false;

                cout << "That number is not in between 1 and 40!";

            }

        }

    }



    return (validInput);

}



void setBoard(string playerBoard[5][5]) {

    string userInput = "";

    bool validInput = false;



    for (int i = 0; i < 5; i++) {



        for (int j = 0; j < 5; j++) {



            userInput = "";

            validInput = false;



            if (i == 2 && j == 2) {

                playerBoard[i][j] = "x";

                continue;

            }



            while (validInput == false) {

                cin >> userInput;

                cout << "You entered: " << userInput << endl;


                if (validBoardInput(userInput, playerBoard)) {

                    playerBoard[i][j] = userInput;

                    validInput = true;

                    cout << userInput << " is valid!" << endl << endl;

                }

                else {

                    cout << " Please try again: " << endl;

                }

            }

        }

    }

}



void move(string playerOneBoard[5][5], string playerTwoBoard[5][5]) {

    srand((unsigned int)time(NULL));

    string random = to_string((rand() % 40) + 1);

    cout << endl << "The number for this round is: " << random << "!" << endl << endl;

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if (playerOneBoard[i][j] == random) {

                playerOneBoard[i][j] = "x";

            }

            if (playerTwoBoard[i][j] == random) {

                playerTwoBoard[i][j] = "x";

            }

        }

    }

}



void printBoards(string playerOneBoard[5][5], string playerTwoBoard[5][5]) {



    cout << "Player One                           Player Two" << endl;

    cout << " -----------------------------        -----------------------------" << endl;

    cout << "|  B     I     N     G     O  |      |  B     I     N     G     O  |";



    for (int i = 0; i < 5; i++) {

        cout << endl;

        cout << "|-----------------------------|      |-----------------------------|" << endl;

        for (int k = 0; k < 2; k++) {

            cout << "|";

            for (int j = 0; j < 5; j++) {

                if (i == 2 && j == 2) {

                    cout << "free" << " |";

                }

                else if (k == 0) {

                    if (playerOneBoard[i][j].size() == 1) {

                        cout << playerOneBoard[i][j] << "    |";

                    }

                    else {

                        cout << playerOneBoard[i][j] << "   |";

                    }

                }

                else if (k == 1) {

                    if (playerTwoBoard[i][j].size() == 1) {

                        cout << playerTwoBoard[i][j] << "    |";

                    }

                    else {

                        cout << playerTwoBoard[i][j] << "   |";

                    }

                }

            }

            cout << "      ";

        }

    }

    cout << endl << " -----------------------------        -----------------------------" << endl;

}


int checkBingo(string playerOneBoard[5][5], string playerTwoBoard[5][5]) {
    int winStatus = 0; //no winners
    bool bingoOne = false;
    bool bingoTwo = false;

    switch (checkRows(playerOneBoard, playerTwoBoard)) {
        case 1:
            bingoOne = true;
            break;
        case 2:
            bingoTwo = true;
            break;
        case 3:
            bingoOne = true;
            bingoTwo = true;
            break;
        default:
            break;
    }

    if (bingoOne == false || bingoTwo == false) {
        switch (checkColumns(playerOneBoard, playerTwoBoard)) {
        case 1:
            bingoOne = true;
            break;
        case 2:
            bingoTwo = true;
            break;
        case 3:
            bingoOne = true;
            bingoTwo = true;
        default:
            break;
        }
    }

    if (bingoOne == false || bingoTwo == false) {
        switch (checkDiagonals(playerOneBoard, playerTwoBoard)) {
        case 1:
            bingoOne = true;
            break;
        case 2:
            bingoTwo = true;
            break;
        case 3:
            bingoOne = true;
            bingoTwo = true;
        default:
            break;
        }
    }


    if (bingoOne && bingoTwo) {
        winStatus = 3;
    }
    else if (bingoOne) {
        winStatus = 1;
    }
    else if (bingoTwo) {
        winStatus = 2;
    }

    //cout << "check bingo: " << winStatus;

    return (winStatus);
}

int checkRows(string playerOneBoard[5][5], string playerTwoBoard[5][5]) {
    bool bingoOne = false;
    bool bingoTwo = false;
    int winStatus = 0;

    for (int i = 0; i < 5; i++) { //check rows board 1
        if (bingoOne) {
            break;
        }
        bingoOne = true;
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                j++;
            }
            if (playerOneBoard[i][j] != "x") {
                bingoOne = false;
                //cout << "row check board 1: not x, i = " << i << " j = " << j << endl;
                //cout << "board 1 [" << i << "][" << j << "] = " << playerOneBoard[i][j] << endl;
            }
        }
    }

    for (int i = 0; i < 5; i++) { //check rows
        if (bingoTwo) {
            break;
        }
        bingoTwo = true;
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                j++;
            }
            if (playerTwoBoard[i][j] != "x") {
                bingoTwo = false;
               // cout << "row check board 2: not x, i = " << i << " j = " << j << endl;
               // cout << "board 2 [" << i << "][" << j << "] = " << playerTwoBoard[i][j] << endl;
            }
        }
    }

    if (bingoOne && bingoTwo) {
        winStatus = 3;
    }
    else if (bingoOne) {
        winStatus = 1;
    }
    else if (bingoTwo) {
        winStatus = 2;
    }

    //cout << "Row status: " << winStatus << endl;
    return (winStatus);
}

int checkColumns(string playerOneBoard[5][5], string playerTwoBoard[5][5]) {
    bool bingoOne = false;
    bool bingoTwo = false;
    int winStatus = 0;
    for (int i = 0; i < 5; i++) { //check columns
        if (bingoOne) {
            break;
        }
        bingoOne = true;
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { //ignore free space
                j++;
            }
            if (playerOneBoard[j][i] != "x") {
                bingoOne = false;
              //  cout << "column check board 1: not x, row = " << j << " column = " << i << endl;
              //  cout << "board 1 [" << j << "][" << i << "] = " << playerOneBoard[j][i] << endl;
            }
        }
    }

    for (int i = 0; i < 5; i++) { //check columns
        if (bingoTwo) {
            break;
        }
        bingoTwo = true;
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { //ignore free space
                j++;
            }
            if (playerTwoBoard[j][i] != "x") {
                bingoTwo = false;
               // cout << "column check board 2: not x, row = " << j << " column = " << i << endl;
               // cout << "board 2 [" << j << "][" << i << "] = " << playerTwoBoard[j][i] << endl;
            }
        }
    }

    if (bingoOne && bingoTwo) {
        winStatus = 3;
    }
    else if (bingoOne) {
        winStatus = 1;
    }
    else if (bingoTwo) {
        winStatus = 2;
    }

    //cout << "Column status... " << winStatus << endl;
    return (winStatus);
}

int checkDiagonals(string playerOneBoard[5][5], string playerTwoBoard[5][5]) {
    bool bingoOne = true;
    bool bingoTwo = true;
    int winStatus = 0;
    for (int i = 0; i < 5; i++) { // check upper left to bottom right diagonal
        if (i == 2) {
            i++;
        }
        if (playerOneBoard[i][i] != "x") {
            bingoOne = false;
        }
    }
    if (bingoOne == false) { //check bottom left to upper right diagonal
        bingoOne = true;
        for (int i = 0, j = 4; i < 5, j >= 0; i++, j--) {
            if (i == 2 && j == 2) {
                i++;
                j--;
            }
            if (playerOneBoard[i][j] != "x") {
                bingoOne = false;
            }
        }
    }

    for (int i = 0; i < 5; i++) { // check upper left to bottom right diagonal
        if (i == 2) {
            i++;
        }
        if (playerTwoBoard[i][i] != "x") {
            bingoTwo = false;
        }
    }
    if (bingoTwo == false) { //check bottom left to upper right diagonal
        bingoTwo = true;
        for (int i = 0, j = 4; i < 5, j >= 0; i++, j--) {
            if (i == 2 && j == 2) {
                i++;
                j--;
            }
            if (playerTwoBoard[i][j] != "x") {
                bingoTwo = false;
            }
        }
    }

    if (bingoOne && bingoTwo) {
        winStatus = 3;
    }
    else if (bingoOne) {
        winStatus = 1;
    }
    else if (bingoTwo) {
        winStatus = 2;
    }

    //cout << "Diagonal status... " << winStatus << endl;
    return (winStatus);
}



bool isGameOver(string playerOneBoard[5][5], string playerTwoBoard[5][5], int round) {

    int winStatus = checkBingo(playerOneBoard, playerTwoBoard);
   // cout << "Checking winStatus... " << endl;

    if (winStatus != 0) {

        switch(winStatus) {

            case 1:

                cout << "BINGO!" << endl;

                
                cout << "Congratulations, Player One! You have won the game after " << round << " rounds!" << endl;

                
                break;

            case 2:

                cout << "                                     BINGO!" << endl;


                cout << "Congratulations, Player Two! You have won the game after " << round << " rounds!" << endl;

                
                break;

            case 3:

                cout << "BINGO!                                BINGO!" << endl;

                cout << "Congratulations to both players for winning the game after " << round << " rounds!" << endl;


                break;

        }

      return (true);

    }

  else {

      return (false);

  }

}

//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24

//25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 1  10 20 24 15 6 17 9





//bool are there any winners

//int who is the winner (1, 2, or 3 for both / 0 for none)

//check rows

//check columns

//check diagonals
