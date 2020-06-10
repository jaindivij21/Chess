//
// Created by Divij Jain on 07-06-2020.
//

#ifndef CHESS_PROJECT_DEFS_H
#define CHESS_PROJECT_DEFS_H

#include <cstdio>
#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;

// global variables
int totalMoves = 0;
int turnOf = 0; // 0 = white && 1 = black


// initializing functions
void initializeBoard();

void printBoard();

void move();

void alternateTurn();

bool statusOfNewPos(int newRank, int newFile, int oldRank, char oldFile);

bool allowPlay();

bool legalityOfMove(int newRank, int newFile, int oldRank, char oldFile);

bool isItCheckMate();

bool validityOfMove(int newRank, int newFile, int oldRank, char oldFile);

void extractArrayPos(char file, int rank);

int rowIndex = 0;
int columnIndex = 0;
int biggerRowIndex;
int biggerColumnIndex;
int smallerRowIndex;
int smallerColumnIndex;

void playGame();

//structure for a piece for every square on the board
struct piece {
    string name;
    char color;
    char file;
    int rank;
    bool ifPresent; // if a square doesnt have a piece it will be false
};

// chessboard initialized of datatype piece
piece chessBoard[8][8];

// board initialization
void initializeBoard() {

    // black
    chessBoard[0][0].name = "bR";
    chessBoard[0][0].color = 'B';
    chessBoard[0][0].file = 'A';
    chessBoard[0][0].rank = 1;
    chessBoard[0][0].ifPresent = true;

    chessBoard[0][1].name = "bH";
    chessBoard[0][1].color = 'B';
    chessBoard[0][1].file = 'B';
    chessBoard[0][1].rank = 1;
    chessBoard[0][1].ifPresent = true;

    chessBoard[0][2].name = "bB";
    chessBoard[0][2].color = 'B';
    chessBoard[0][2].file = 'C';
    chessBoard[0][2].rank = 1;
    chessBoard[0][2].ifPresent = true;

    chessBoard[0][3].name = "bQ";
    chessBoard[0][3].color = 'B';
    chessBoard[0][3].file = 'D';
    chessBoard[0][3].rank = 1;
    chessBoard[0][3].ifPresent = true;

    chessBoard[0][4].name = "bK";
    chessBoard[0][4].color = 'B';
    chessBoard[0][4].file = 'E';
    chessBoard[0][4].rank = 1;
    chessBoard[0][4].ifPresent = true;

    chessBoard[0][5].name = "bB";
    chessBoard[0][5].color = 'B';
    chessBoard[0][5].file = 'F';
    chessBoard[0][5].rank = 1;
    chessBoard[0][5].ifPresent = true;

    chessBoard[0][6].name = "bH";
    chessBoard[0][6].color = 'B';
    chessBoard[0][6].file = 'G';
    chessBoard[0][6].rank = 1;
    chessBoard[0][6].ifPresent = true;

    chessBoard[0][7].name = "bR";
    chessBoard[0][7].color = 'B';
    chessBoard[0][7].file = 'H';
    chessBoard[0][7].rank = 1;
    chessBoard[0][7].ifPresent = true;

    for (int i = 1; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            char temp = 65 + j;
            chessBoard[i][j].name = "bP";
            chessBoard[i][j].color = 'B';
            chessBoard[i][j].file = temp;
            chessBoard[i][j].rank = i;
            chessBoard[i][j].ifPresent = true;
        }
    }

    // white
    chessBoard[7][0].name = "wR";
    chessBoard[7][0].color = 'W';
    chessBoard[7][0].file = 'A';
    chessBoard[7][0].rank = 8;
    chessBoard[7][0].ifPresent = true;

    chessBoard[7][1].name = "wH";
    chessBoard[7][1].color = 'W';
    chessBoard[7][1].file = 'B';
    chessBoard[7][1].rank = 8;
    chessBoard[7][1].ifPresent = true;

    chessBoard[7][2].name = "wB";
    chessBoard[7][2].color = 'W';
    chessBoard[7][2].file = 'C';
    chessBoard[7][2].rank = 8;
    chessBoard[7][2].ifPresent = true;

    chessBoard[7][3].name = "wQ";
    chessBoard[7][3].color = 'W';
    chessBoard[7][3].file = 'D';
    chessBoard[7][3].rank = 8;
    chessBoard[7][3].ifPresent = true;

    chessBoard[7][4].name = "wK";
    chessBoard[7][4].color = 'W';
    chessBoard[7][4].file = 'E';
    chessBoard[7][4].rank = 8;
    chessBoard[7][4].ifPresent = true;

    chessBoard[7][5].name = "wB";
    chessBoard[7][5].color = 'W';
    chessBoard[7][5].file = 'F';
    chessBoard[7][5].rank = 8;
    chessBoard[7][5].ifPresent = true;

    chessBoard[7][6].name = "wH";
    chessBoard[7][6].color = 'W';
    chessBoard[7][6].file = 'G';
    chessBoard[7][6].rank = 8;
    chessBoard[7][6].ifPresent = true;

    chessBoard[7][7].name = "wR";
    chessBoard[7][7].color = 'W';
    chessBoard[7][7].file = 'H';
    chessBoard[7][7].rank = 8;
    chessBoard[7][7].ifPresent = true;

    for (int i = 6; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            char temp = 65 + j;
            chessBoard[i][j].name = "wP";
            chessBoard[i][j].color = 'W';
            chessBoard[i][j].file = temp;
            chessBoard[i][j].rank = i;
            chessBoard[i][j].ifPresent = true;
        }
    }

    // making ifPresent as false for all the other squares and printing -- there
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            chessBoard[i][j].ifPresent = false;
            chessBoard[i][j].name = "--";
        }
    }
}

// printing the chess board on the console
void printBoard() {
    cout
            << "                             A                       B                       C                       D                       E                       F                       G                       H             "
            << "\n"
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         1       #          " << chessBoard[0][0].name << "           #          " << chessBoard[0][1].name
         << "           #          " << chessBoard[0][2].name << "           #          " << chessBoard[0][3].name
         << "           #          " << chessBoard[0][4].name << "           #          " << chessBoard[0][5].name
         << "           #          " << chessBoard[0][6].name << "           #          " << chessBoard[0][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         2       #          " << chessBoard[1][0].name << "           #          " << chessBoard[1][1].name
         << "           #          " << chessBoard[1][2].name << "           #          " << chessBoard[1][3].name
         << "           #          " << chessBoard[1][4].name << "           #          " << chessBoard[1][5].name
         << "           #          " << chessBoard[1][6].name << "           #          " << chessBoard[1][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         3       #          " << chessBoard[2][0].name << "           #          " << chessBoard[2][1].name
         << "           #          " << chessBoard[2][2].name << "           #          " << chessBoard[2][3].name
         << "           #          " << chessBoard[2][4].name << "           #          " << chessBoard[2][5].name
         << "           #          " << chessBoard[2][6].name << "           #          " << chessBoard[2][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         4       #          " << chessBoard[3][0].name << "           #          " << chessBoard[3][1].name
         << "           #          " << chessBoard[3][2].name << "           #          " << chessBoard[3][3].name
         << "           #          " << chessBoard[3][4].name << "           #          " << chessBoard[3][5].name
         << "           #          " << chessBoard[3][6].name << "           #          " << chessBoard[3][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         5       #          " << chessBoard[4][0].name << "           #          " << chessBoard[4][1].name
         << "           #          " << chessBoard[4][2].name << "           #          " << chessBoard[4][3].name
         << "           #          " << chessBoard[4][4].name << "           #          " << chessBoard[4][5].name
         << "           #          " << chessBoard[4][6].name << "           #          " << chessBoard[4][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         6       #          " << chessBoard[5][0].name << "           #          " << chessBoard[5][1].name
         << "           #          " << chessBoard[5][2].name << "           #          " << chessBoard[5][3].name
         << "           #          " << chessBoard[5][4].name << "           #          " << chessBoard[5][5].name
         << "           #          " << chessBoard[5][6].name << "           #          " << chessBoard[5][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         7       #          " << chessBoard[6][0].name << "           #          " << chessBoard[6][1].name
         << "           #          " << chessBoard[6][2].name << "           #          " << chessBoard[6][3].name
         << "           #          " << chessBoard[6][4].name << "           #          " << chessBoard[6][5].name
         << "           #          " << chessBoard[6][6].name << "           #          " << chessBoard[6][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout << "         8       #          " << chessBoard[7][0].name << "           #          " << chessBoard[7][1].name
         << "           #          " << chessBoard[7][2].name << "           #          " << chessBoard[7][3].name
         << "           #          " << chessBoard[7][4].name << "           #          " << chessBoard[7][5].name
         << "           #          " << chessBoard[7][6].name << "           #          " << chessBoard[7][7].name
         << "           #  " << endl;
    cout
            << "                 #                       #                       #                       #                       #                       #                       #                       #                       # "
            << endl;
    cout
            << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # "
            << endl;
    cout << "\n\n"
         << endl;
}

// extracting the array index from given file and rank of a chessboard
void extractArrayPos(char file, int rank) {
    // e.g A 1 == rowIndex = 0 & columnIndex = 0
    rowIndex = rank - 1;
    columnIndex = file - 65;
}

// change turn after every ply
void alternateTurn() {
    if (totalMoves == 0)
        turnOf = 0;
    else
        turnOf = !turnOf;
}

// function to execute move from one location to another
void move() {

    alternateTurn();

    string pieceToMove;
    char newPositionFile;
    int newPositionRank;
    char oldPositionFile;
    int oldPositionRank;

    do {
        do {
            cout << "Enter the ";
            if (turnOf == 0) {
                cout << "White";
            } else {
                cout << "Black";
            }
            cout << " piece to move (e.g. 'bP')" << endl;
            cin >> pieceToMove;
            cout << "Enter its old position (e.g. 'D 3')" << endl;
            cin >> oldPositionFile >> oldPositionRank;

            extractArrayPos(oldPositionFile, oldPositionRank);
            if ((turnOf == 0 && chessBoard[rowIndex][columnIndex].color == 'W') ||
                (turnOf == 1 && chessBoard[rowIndex][columnIndex].color == 'B')) {
                if (chessBoard[rowIndex][columnIndex].name != pieceToMove) {
                    cout << "ERROR! Input Position doesnt match with the piece!"
                         << "\n\n"
                         << endl;
                    continue;
                }
                break;
            } else {
                cout << "ERROR! Move the piece of your colour"
                     << "\n\n"
                     << endl;
            }

        } while (true);

        cout << "Enter new position (e.g. 'D 5')" << endl;
        cin >> newPositionFile >> newPositionRank;
        extractArrayPos(newPositionFile, newPositionRank); // rowIndex columnIndex

        // check the validity of the move and status of destination square
        bool ifValid1 = validityOfMove(rowIndex, columnIndex, oldPositionRank, oldPositionFile);
        bool ifValid2 = statusOfNewPos(rowIndex, columnIndex, oldPositionRank, oldPositionFile);

        // only proceed to moving if the move is valid(inside the chessboard), legal(regarding the specific pieces) and status of destinaiton is ok(its either empty or piece of other color is present)
        if (ifValid1 && ifValid2) {
            break;
        } else {
            cout << "ERROR! Not a valid Move"
                 << "\n\n"
                 << endl;
        }
    } while (true);

    extractArrayPos(oldPositionFile, oldPositionRank); ///////////////////////////////////////////// can be removed
    char tempColor = chessBoard[rowIndex][columnIndex].color;

    extractArrayPos(newPositionFile, newPositionRank);
    // we get new values in variables rowIndex and columnIndex
    chessBoard[rowIndex][columnIndex].name = pieceToMove;
    chessBoard[rowIndex][columnIndex].file = newPositionFile;
    chessBoard[rowIndex][columnIndex].rank = newPositionRank;
    chessBoard[rowIndex][columnIndex].ifPresent = true;
    chessBoard[rowIndex][columnIndex].color = tempColor;

    extractArrayPos(oldPositionFile, oldPositionRank);
    chessBoard[rowIndex][columnIndex].name = "--";
    chessBoard[rowIndex][columnIndex].ifPresent = false;
    chessBoard[rowIndex][columnIndex].file = oldPositionFile;
    chessBoard[rowIndex][columnIndex].rank = oldPositionRank;

    totalMoves++;
}

// function to move from one location to another and cut the piece of opposite colour
bool statusOfNewPos(int newRank, int newFile, int oldRank, char oldFile) {

    // check the status of new position
    if (!chessBoard[newRank][newFile].ifPresent) // its empty
        return true;
    else // it isnt empty
    {
        extractArrayPos(oldFile, oldRank);
        if (chessBoard[newRank][newFile].color ==
            chessBoard[rowIndex][columnIndex].color) // it is the same colour as the piece you are moving
        {
            cout << "Your  piece already present there!" << endl;
            return false;
        } else // its not the same colour which means it can cut the other piece
            return true;
    }
}

// checks for the conditions required to play the game; if not satisfied game-over
bool allowPlay() {
    if (totalMoves == 100)
        return false;
    else if (isItCheckMate() == true)
        return false;
    else
        return true;
}

// check for validity
bool validityOfMove(int newRank, int newFile, int oldRank, char oldFile) {
    // check if the new position is not outside the array
    if ((newRank >= 0 && newRank <= 7) && (newFile >= 0 && newFile <= 7)) {
        // if yes, then check for the legality of the move
        if (legalityOfMove(newRank, newFile, oldRank, oldFile))
            return true;
        else {
            cout << "ERROR! This move is not legal!" << endl;
            return false;
        }
    } else {
        cout << "ERROR! The move is Out Of Bounds!" << endl;
        return false;
    }
}

// checking the legality of the move wrt to the piece's rules and also check if something is blocking the way
bool legalityOfMove(int newRank, int newFile, int oldRank, char oldFile) {
    extractArrayPos(oldFile, oldRank); // NOW newRank, newFile, rowIndex, columnIndex
    string tempPiece = (chessBoard[rowIndex][columnIndex].name);

    char nameOfThePiece;

    if (tempPiece == "wP" || tempPiece == "bP") {
        nameOfThePiece = 'P';
    }
    if (tempPiece == "wR" || tempPiece == "bR") {
        nameOfThePiece = 'R';
    }
    if (tempPiece == "wH" || tempPiece == "bH") {
        nameOfThePiece = 'H';
    }
    if (tempPiece == "wB" || tempPiece == "bB") {
        nameOfThePiece = 'B';
    }
    if (tempPiece == "wQ" || tempPiece == "bQ") {
        nameOfThePiece = 'Q';
    }
    if (tempPiece == "wK" || tempPiece == "bK") {
        nameOfThePiece = 'K';
    }

    biggerRowIndex = max(rowIndex, newRank);
    biggerColumnIndex = max(columnIndex, newFile);
    smallerRowIndex = min(rowIndex, newRank);
    smallerColumnIndex = min(columnIndex, newFile);

    switch (nameOfThePiece) {
        // legality of pawns
        case 'P':
            // if pawn is moving to an empty space; it can only move one space forward
            if (!chessBoard[newRank][newFile].ifPresent) {
                return newRank == rowIndex - 1 && newFile == columnIndex;
            }
                // if pawn wants to cut someone
            else {
                return (newRank == rowIndex - 1 && newFile == columnIndex - 1) ||
                       (newRank == rowIndex - 1 && newFile == columnIndex + 1);
            }
            break;

            // legality of Rooks
        case 'R':
            // Rook moves in the same row
            if (newRank == rowIndex) {
                // now check if all the squares in bw source and destination are empty
                int columnOffset = newFile - columnIndex;
                for (int i = 0; i < columnOffset; i++) {
                    if (chessBoard[newRank][columnIndex + i].ifPresent)
                        return false;
                }
                return true;
            }
                // rook moves in the same column
            else if (newFile == columnIndex) {
                // now check if all the squares in bw source and destinations are empty
                int rowOffset = newFile - columnIndex;
                for (int i = 0; i < rowOffset; i++) {
                    if (chessBoard[rowIndex + i][newFile].ifPresent)
                        return false;
                }
                return true;
            } else
                return false;

            break;

            // legality of Horse
        case 'H':
            // for horse we dont need to check the path towards the destination square
            // also we already have checked if the destination square is empty or not using statusOfNewPos Function

            // it moves one column and two rows away
            if ((columnIndex == newFile + 1) || (columnIndex == newFile - 1)) {
                if ((rowIndex == newRank + 2) || (rowIndex == newRank - 2)) {
                    return true;
                }
            }

            // it moves one row and two columns away
            if ((columnIndex == newFile + 2) || (columnIndex == newFile - 2)) {
                if ((rowIndex == newRank + 1) || (rowIndex == newRank - 1)) {
                    return true;
                }
            }
            return false;

            break;

            // legality of bishop
        case 'B':
            // it moves diagonally
            // make sure it moves diagonally
            if (biggerRowIndex - smallerRowIndex == biggerColumnIndex - smallerColumnIndex) {
                // checking if squares in the way are unoccupied
                int a = rowIndex;
                int b = columnIndex;
                if (newRank < rowIndex && newFile < columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a--;
                        b--;
                    }
                    return true;
                }
                if (newRank < rowIndex && newFile > columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a--;
                        b++;
                    }
                    return true;
                }
                if (newRank > rowIndex && newFile < columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a++;
                        b--;
                    }
                    return true;
                }
                if (newRank > rowIndex && newFile > columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a++;
                        b++;
                    }
                    return true;
                }
            }

                // if it doesn't move diagonal
            else {
                return false;
            }
            break;

            // legality of Queen
        case 'Q':
            // if queen moves in same row
            if (newRank == rowIndex) {
                // now check if all the squares in bw source and destination are empty
                int columnOffset = newFile - columnIndex;
                for (int i = 0; i < columnOffset; i++) {
                    if (chessBoard[newRank][columnIndex + i].ifPresent)
                        return false;
                }
                return true;
            }
            // if queen moves in the same column
            if (newFile == columnIndex) {
                // now check if all the squares in bw source and destinations are empty
                int rowOffset = newFile - columnIndex;
                for (int i = 0; i < rowOffset; i++) {
                    if (chessBoard[rowIndex + i][newFile].ifPresent)
                        return false;
                }
                return true;
            }
            // if queen moves diagonally
            // make sure it moves diagonal
            if (biggerRowIndex - smallerRowIndex == biggerColumnIndex - smallerColumnIndex) {
                // checking if squares in the way are unoccupied
                int a = rowIndex;
                int b = columnIndex;
                if (newRank < rowIndex && newFile < columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a--;
                        b--;
                    }
                    return true;
                }
                if (newRank < rowIndex && newFile > columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a--;
                        b++;
                    }
                    return true;
                }
                if (newRank > rowIndex && newFile < columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a++;
                        b--;
                    }
                    return true;
                }
                if (newRank > rowIndex && newFile > columnIndex) {
                    while (a == newRank && b == newFile) {
                        if (chessBoard[a][b].ifPresent)
                            return false;
                        a++;
                        b++;
                    }
                    return true;
                }
            }

            return false;
            break;

            // legality of King
        case 'K':
            int rowDelta = newRank - rowIndex;
            int colDelta = newFile - columnIndex;

            // since king moves just one step, no need to check for obstructions
            // the difference between the destination and the source must be bw -1 and 1 both included
            return ((rowDelta >= -1) && (rowDelta <= 1)) && ((colDelta >= -1) && (colDelta <= 1));

    }
    return false;
}

// TO DO
//check for check mate
bool isItCheckMate() {
    return false;
}

// MAIN FUNCTION
void playGame() {
    // initialize the board
    initializeBoard();
    printBoard();

    // test conditions if the game is over or not
    while (allowPlay()) {
        move();
        printBoard();
    }

    cout << "Thanks for playing" << endl;
}

#endif //CHESS_PROJECT_DEFS_H
