//
// Created by Divij Jain on 07-06-2020.
//

#ifndef CHESS_PROJECT_DEFS_H
#define CHESS_PROJECT_DEFS_H

#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

// initializing functions
void initializeBoard();
void printBoard();
void move();

void extractArrayPos(string piece, char file, int rank);
int rowIndex=0;
int columnIndex=0;

void playGame();

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
    cout << "                             A                       B                       C                       D                       E                       F                       G                       H             "
         << "\n"
         << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         1       #          " << chessBoard[0][0].name << "           #          " << chessBoard[0][1].name << "           #          " << chessBoard[0][2].name << "           #          " << chessBoard[0][3].name << "           #          " << chessBoard[0][4].name << "           #          " << chessBoard[0][5].name << "           #          " << chessBoard[0][6].name << "           #          " << chessBoard[0][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         2       #          " << chessBoard[1][0].name << "           #          " << chessBoard[1][1].name << "           #          " << chessBoard[1][2].name << "           #          " << chessBoard[1][3].name << "           #          " << chessBoard[1][4].name << "           #          " << chessBoard[1][5].name << "           #          " << chessBoard[1][6].name << "           #          " << chessBoard[1][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         3       #          " << chessBoard[2][0].name << "           #          " << chessBoard[2][1].name << "           #          " << chessBoard[2][2].name << "           #          " << chessBoard[2][3].name << "           #          " << chessBoard[2][4].name << "           #          " << chessBoard[2][5].name << "           #          " << chessBoard[2][6].name << "           #          " << chessBoard[2][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         4       #          " << chessBoard[3][0].name << "           #          " << chessBoard[3][1].name << "           #          " << chessBoard[3][2].name << "           #          " << chessBoard[3][3].name << "           #          " << chessBoard[3][4].name << "           #          " << chessBoard[3][5].name << "           #          " << chessBoard[3][6].name << "           #          " << chessBoard[3][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         5       #          " << chessBoard[4][0].name << "           #          " << chessBoard[4][1].name << "           #          " << chessBoard[4][2].name << "           #          " << chessBoard[4][3].name << "           #          " << chessBoard[4][4].name << "           #          " << chessBoard[4][5].name << "           #          " << chessBoard[4][6].name << "           #          " << chessBoard[4][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         6       #          " << chessBoard[5][0].name << "           #          " << chessBoard[5][1].name << "           #          " << chessBoard[5][2].name << "           #          " << chessBoard[5][3].name << "           #          " << chessBoard[5][4].name << "           #          " << chessBoard[5][5].name << "           #          " << chessBoard[5][6].name << "           #          " << chessBoard[5][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         7       #          " << chessBoard[6][0].name << "           #          " << chessBoard[6][1].name << "           #          " << chessBoard[6][2].name << "           #          " << chessBoard[6][3].name << "           #          " << chessBoard[6][4].name << "           #          " << chessBoard[6][5].name << "           #          " << chessBoard[6][6].name << "           #          " << chessBoard[6][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "         8       #          " << chessBoard[7][0].name << "           #          " << chessBoard[7][1].name << "           #          " << chessBoard[7][2].name << "           #          " << chessBoard[7][3].name << "           #          " << chessBoard[7][4].name << "           #          " << chessBoard[7][5].name << "           #          " << chessBoard[7][6].name << "           #          " << chessBoard[7][7].name << "           #  " << endl;
    cout << "                 #                       #                       #                       #                       #                       #                       #                       #                       # " << endl;
    cout << "                 #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   #   # " << endl;
    cout << "\n\n"
         << endl;
}

void extractArrayPos(char file, int rank)
{
    // e.g A 1 == rowIndex = 0 & columnIndex = 0
    rowIndex = rank - 1;
    columnIndex = file - 65;
    cout<<rowIndex<<" "<<columnIndex<<endl;
}

void move()
{
    string pieceToMove;
    char newPositionFile;
    int newPositionRank;
    char oldPositionFile;
    int oldPositionRank;
    cout << "Enter the piece to move, its old postion & the new location" << endl;
    cin >> pieceToMove >> oldPositionFile >> oldPositionRank >> newPositionFile >> newPositionRank;
    //cout << "to";


    extractArrayPos(oldPositionFile, oldPositionRank);
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
}

void playGame()
{
    initializeBoard();
    printBoard();
    int movepiece = 0;
    while (movepiece!=-1)
    {
        move();
        printBoard();
        cout<<"To move enter 1 else enter -1"<<endl;
        cin>>movepiece;
    }
}





#endif //CHESS_PROJECT_DEFS_H
