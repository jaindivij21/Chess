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
char turnOf = 'W'; // tells which color's turn it is!
string tempPiece;
char nameOfThePiece;
int a, b;
int rowDelta, colDelta;
int columnOffset;
int rowOffset;

int tempVariable;

// initializing functions
void initializeBoard();

void printBoard();

void move();

void alternateTurn();

bool statusOfNewPos(int newRank, int newFile, int oldRank, char oldFile);

int allowPlay();

bool legalityOfMove(int newRank, int newFile, int oldRank, char oldFile);

bool isItCheckMate();

bool isItStaleMate();

int validityOfMove(int newRank, int newFile, int oldRank, char oldFile);

void extractArrayPos(char file, int rank);

bool isItCheck();

bool canKingMove();

int rowIndex = 0;
int columnIndex = 0;
int biggerRowIndex;
int biggerColumnIndex;
int smallerRowIndex;
int smallerColumnIndex;

void playGame(string player1, string player2, char player1color, char player2color);

//structure for a piece for every square on the board
struct piece
{
    string name;
    char color;
    char file;
    int rank;
    bool ifPresent; // if a square doesnt have a piece it will be false
};

// chessboard initialized of datatype piece
piece chessBoard[8][8];

// board initialization
void initializeBoard()
{

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

    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
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

    for (int i = 6; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char temp = 65 + j;
            chessBoard[i][j].name = "wP";
            chessBoard[i][j].color = 'W';
            chessBoard[i][j].file = temp;
            chessBoard[i][j].rank = i;
            chessBoard[i][j].ifPresent = true;
        }
    }

    // making ifPresent as false for all the other squares and printing -- there
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessBoard[i][j].ifPresent = false;
            chessBoard[i][j].name = "--";
        }
    }
}

// printing the chess board on the console
void printBoard()
{
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
void extractArrayPos(char file, int rank)
{
    // e.g A 1 == rowIndex = 0 & columnIndex = 0
    rowIndex = rank - 1;
    columnIndex = file - 65;
}

// change turn after every ply
void alternateTurn()
{
    if (totalMoves == 0)
        turnOf = 'W';
    else
        turnOf = (turnOf == 'W') ? 'B' : 'W';
}

// function to execute move from one location to another
void move()
{
    string pieceToMove;
    char newPositionFile;
    int newPositionRank;
    char oldPositionFile;
    int oldPositionRank;

    do
    {
        do
        {
            cout << "Enter the ";
            if (turnOf == 'W')
            {
                cout << "White";
            }
            else
            {
                cout << "Black";
            }
            cout << " piece to move (e.g. 'bP')" << endl;
            cin >> pieceToMove;
            cout << "Enter its old position (e.g. 'D 3')" << endl;
            cin >> oldPositionFile >> oldPositionRank;

            extractArrayPos(oldPositionFile, oldPositionRank);

            if ((turnOf == 'W' && chessBoard[rowIndex][columnIndex].color == 'W') ||
                (turnOf == 'B' && chessBoard[rowIndex][columnIndex].color == 'B'))
            {
                if (chessBoard[rowIndex][columnIndex].name != pieceToMove)
                {
                    cout << "ERROR! Input Position doesnt match with the piece!"
                         << "\n\n"
                         << endl;
                    continue;
                }
                break;
            }
            else
            {
                cout << "ERROR! Move the piece of your colour"
                     << "\n\n"
                     << endl;
            }

        } while (true);

        cout << "Enter new position (e.g. 'D 5')" << endl;
        cin >> newPositionFile >> newPositionRank;
        extractArrayPos(newPositionFile, newPositionRank); // rowIndex columnIndex

        // check the validity of the move and status of destination square
        bool ifValid2 = statusOfNewPos(rowIndex, columnIndex, oldPositionRank, oldPositionFile);
        if (ifValid2 == false)
        {
            cout << "Your  piece already present there!" << endl;
        }
        extractArrayPos(newPositionFile, newPositionRank);
        int ifValid1 = validityOfMove(rowIndex, columnIndex, oldPositionRank, oldPositionFile);
        if (ifValid1 == 0)
        {
            cout << "ERROR! This move is not legal!" << endl;
        }
        if (ifValid1 == -1)
        {
            cout << "ERROR! The move is Out Of Bounds!" << endl;
        }
        // only proceed to moving if the move is valid(inside the chessboard), legal(regarding the specific pieces) and status of destinaiton is ok(its either empty or piece of other color is present)
        if (ifValid1 && ifValid2)
        {
            break;
        }
        else
        {
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
bool statusOfNewPos(int newRank, int newFile, int oldRank, char oldFile)
{

    // check the status of new position
    if (!chessBoard[newRank][newFile].ifPresent) // its empty
        return true;
    else // it isnt empty
    {
        extractArrayPos(oldFile, oldRank);
        if (chessBoard[newRank][newFile].color ==
            chessBoard[rowIndex][columnIndex].color) // it is the same colour as the piece you are moving
        {
            return false;
        }
        else // its not the same colour which means it can cut the other piece
            return true;
    }
}

// checks for the conditions required to play the game; if not satisfied game-over
int allowPlay()
{
    if (totalMoves == 100)
        return -1;
    else if (isItCheckMate() == true)
        return 0;
    else if (isItStaleMate() == true)
        return 2;
    else
        return 1;
}

// check for validity
int validityOfMove(int newRow, int newColumn, int oldRank, char oldFile) // newRow and newColumn are array indexes but oldRank and oldFile are RANK AND FILE respectively!
{
    // check if the new position is not outside the array
    if ((newRow >= 0 && newRow <= 7) && (newColumn >= 0 && newColumn <= 7))
    {
        // if yes, then check for the legality of the move
        if (legalityOfMove(newRow, newColumn, oldRank, oldFile))
            return 1;
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

// checking the legality of the move wrt to the piece's rules and also check if something is blocking the way
bool legalityOfMove(int newRow, int newColumn, int oldRank, char oldFile)
{
    extractArrayPos(oldFile, oldRank); // NOW newRow, newColumn, rowIndex, columnIndex
    tempPiece = (chessBoard[rowIndex][columnIndex].name);

    if (tempPiece == "wP" || tempPiece == "bP")
    {
        nameOfThePiece = 'P';
    }
    if (tempPiece == "wR" || tempPiece == "bR")
    {
        nameOfThePiece = 'R';
    }
    if (tempPiece == "wH" || tempPiece == "bH")
    {
        nameOfThePiece = 'H';
    }
    if (tempPiece == "wB" || tempPiece == "bB")
    {
        nameOfThePiece = 'B';
    }
    if (tempPiece == "wQ" || tempPiece == "bQ")
    {
        nameOfThePiece = 'Q';
    }
    if (tempPiece == "wK" || tempPiece == "bK")
    {
        nameOfThePiece = 'K';
    }

    biggerRowIndex = max(rowIndex, newRow);
    biggerColumnIndex = max(columnIndex, newColumn);
    smallerRowIndex = min(rowIndex, newRow);
    smallerColumnIndex = min(columnIndex, newColumn);

    switch (nameOfThePiece)
    {

    // legality of pawns
    case 'P':
        if (chessBoard[rowIndex][columnIndex].color == 'W')
        {
            // if pawn is moving to an empty space; it can only move one space forward
            if (chessBoard[newRow][newColumn].ifPresent == false)
            {
                if (newRow == rowIndex - 1 && newColumn == columnIndex)
                    return true;
                else
                    return false;
            }
            // if pawn wants to cut someone
            else
            {
                if (newRow == rowIndex - 1)
                {
                    if (newColumn == columnIndex - 1 || newColumn == columnIndex + 1)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if (chessBoard[rowIndex][columnIndex].color == 'B')
        {
            // if pawn is moving to an empty space; it can only move one space forward
            if (chessBoard[newRow][newColumn].ifPresent == false)
            {
                if (newRow == rowIndex + 1 && newColumn == columnIndex)
                    return true;
                else
                    return false;
            }
            // if pawn wants to cut someone
            else
            {
                if ((newRow == rowIndex + 1 && newColumn == columnIndex - 1) ||
                    (newRow == rowIndex + 1 && newColumn == columnIndex + 1))
                    return true;
                else
                    return false;
            }
        }

    // legality of Rooks
    case 'R':
        // Rook moves in the same row
        if (newRow == rowIndex)
        {
            // now check if all the squares in bw source and destination are empty
            columnOffset = biggerColumnIndex - smallerColumnIndex;

            if (newColumn > columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex + i].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newColumn < columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex - i].ifPresent == true)
                        return false;
                }
                return true;
            }
        }

        // rook moves in the same column
        else if (newColumn == columnIndex)
        {
            // now check if all the squares in bw source and destinations are empty
            rowOffset = biggerRowIndex - smallerRowIndex;

            if (newRow > rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[newRow + i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newRow < rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[newRow - i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }
        }
        else
            return false;

    // legality of Horse
    case 'H':
        // for horse we dont need to check the path towards the destination square
        // also we already have checked if the destination square is empty or not using statusOfNewPos Function

        // it moves one column and two rows away
        if ((columnIndex == newColumn + 1) || (columnIndex == newColumn - 1))
        {
            if ((rowIndex == newRow + 2) || (rowIndex == newRow - 2))
            {
                return true;
            }
        }
        // it moves one row and two columns away
        else if ((columnIndex == newColumn + 2) || (columnIndex == newColumn - 2))
        {
            if ((rowIndex == newRow + 1) || (rowIndex == newRow - 1))
            {
                return true;
            }
        }
        // some other movement
        else
            return false;

    // legality of bishop
    case 'B':
        // it moves diagonally
        // make sure it moves diagonally
        if (biggerRowIndex - smallerRowIndex == biggerColumnIndex - smallerColumnIndex)
        {
            // checking if squares in the way are unoccupied
            a = rowIndex;
            b = columnIndex;
            if (newRow < rowIndex && newColumn < columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b--;
                }
                return true;
            }
            if (newRow < rowIndex && newColumn > columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b++;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn < columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b--;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn > columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b++;
                }
                return true;
            }
        }
        // if it doesn't move diagonal
        else
            return false;

    // legality of Queen
    case 'Q':
        // if queen moves in same row
        if (newRow == rowIndex)
        {
            // now check if all the squares in bw source and destination are empty
            columnOffset = biggerColumnIndex - smallerColumnIndex;

            if (newColumn > columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex + i].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newColumn < columnIndex)
            {
                for (int i = 1; i < columnOffset; i++)
                {
                    if (chessBoard[newRow][columnIndex - i].ifPresent == true)
                        return false;
                }
                return true;
            }
        }

        // if queen moves in the same column
        else if (newColumn == columnIndex)
        {
            // now check if all the squares in bw source and destinations are empty
            rowOffset = biggerRowIndex - smallerRowIndex;

            if (newRow > rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[newRow + i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }

            if (newRow < rowIndex)
            {
                for (int i = 1; i < rowOffset; i++)
                {
                    if (chessBoard[newRow - i][columnIndex].ifPresent == true)
                        return false;
                }
                return true;
            }
        }

        // if queen moves diagonally
        // make sure it moves diagonal
        else if (biggerRowIndex - smallerRowIndex == biggerColumnIndex - smallerColumnIndex)
        {
            // checking if squares in the way are unoccupied
            a = rowIndex;
            b = columnIndex;
            if (newRow < rowIndex && newColumn < columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b--;
                }
                return true;
            }
            if (newRow < rowIndex && newColumn > columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a--;
                    b++;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn < columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b--;
                }
                return true;
            }
            if (newRow > rowIndex && newColumn > columnIndex)
            {
                while (a == newRow && b == newColumn)
                {
                    if (chessBoard[a][b].ifPresent == true)
                        return false;
                    a++;
                    b++;
                }
                return true;
            }
        }
        else
            return false;

    // legality of King
    case 'K':
        rowDelta = newRow - rowIndex;
        colDelta = newColumn - columnIndex;

        // since king moves just one step, no need to check for obstructions
        // the difference between the destination and the source must be bw -1 and 1 both included
        if (((rowDelta >= -1) && (rowDelta <= 1)) && ((colDelta >= -1) && (colDelta <= 1)))
            return true;
        else
            return false;
    }
}

// TO DO
//check for stale mate
bool isItStaleMate()
{
    return false;
}

// TO DO
// check for check mate
bool isItCheckMate()
{
    if (isItCheck() == true)
    {
        // check if the king can move or not
        if (canKingMove() == true)
        {
            // king it can move
            return false;
        }
        // if king cannot move

        // king aur piece ke beech me koi nahi aa sakta
        if ()
        {
            // agar koi aa sakta hai
            return false;
        }
        // koi beech me aa sakta hai

        // can someone take out the piece that checked the king
        if ()
        {
            // agr koi hai aesa jo cut kar sakta hai
            return false;
        }
        // agr koi k=cut ni kar sakta
        return true;
    }
    // check for other conditions 2
    else
        return false;
}

bool canKingMove()
{

}

// checks for Check for current colour i.e turnOf colour
bool isItCheck()
{
    // working: find the coordinates of the king. then for every opposite color piece check validity/legality of piece to that destination!

    // coordinates of the king
    int kingColumn = 0;
    int kingRow = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((chessBoard[i][j].name == "wK" || chessBoard[i][j].name == "bK"))
            {
                if (chessBoard[i][j].color == turnOf)
                {
                    kingRow = i;
                    kingColumn = j;
                }
            }
        }
    }

    // stores the opposite color
    char oppColor = (turnOf == 'W') ? 'B' : 'W';

    // now for each piece of other color; check if they can reach the king
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((chessBoard[i][j].ifPresent == true) && (chessBoard[i][j].color == oppColor))
            {
                int extractedRank = i + 1;
                char extractedFile = j + 65;

                if (validityOfMove(kingRow, kingColumn, extractedRank, extractedFile) == 1)
                {
                    cout << "Its a CHECK! for"
                         << " " << turnOf << "\n\n"
                         << endl;
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }
    return false;
}

// MAIN FUNCTION
void playGame(string player1, string player2, char player1color, char player2color)
{
    // initialize the board
    initializeBoard();
    printBoard();

    // test conditions if the game is over or not
    while ((tempVariable = allowPlay()) == 1)
    {
        move();
        printBoard();
        alternateTurn(); // W-----B
    }

    // end results
    if (tempVariable == -1)
    {
        cout << "Exceeded 100 moves! Its a DRAW!" << endl;
    }
    if (tempVariable == 2)
    {
        cout << "StaleMate! Its a DRAW!" << endl;
    }
    if (tempVariable == 0)
    {
        char oppColor;
        if (turnOf == 'W')
            oppColor = 'B';
        else
            oppColor = 'W';

        if (oppColor == player1color)
            cout << "Check Mate! Player" << player1 << "WINS!" << endl;
        if (oppColor == player2color)
            cout << "Check Mate! Player" << player2 << "WINS!" << endl;
    }
    cout << "Thanks for playing" << endl;
}

#endif //CHESS_PROJECT_DEFS_H

// Condition for check mate is totally  wrong!
// check mate happens when
// 1) its a check
// 1a) king cannot move
// 1b) no one comes bw the piece that checked and the king
// 1c) someone can take out the piece that checked
// 2) if some one walks into a check himself i.e king gets in check himself

// stalemate logic is all wrong

// BUGS:
//None Right now!