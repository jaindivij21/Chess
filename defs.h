#include <stdio.h>
#include <iostream>
#include <conio.h>

*using namespace std;


void initializeBoard();
void printBoard();
void playGame();

struct piece{
    string name;
    char color;
    char file;
    int rank;
    bool ifPresent;
};

piece chessBoard[8][8];


void initializeBoard(){
    chessBoard[0][0].name="ROOK";
    chessBoard[0][0].color='B';
    chessBoard[0][0].file='A';
    chessBoard[0][0].rank=1;
    chessBoard[0][0].ifPresent=true;

    chessBoard[0][1].name="KNIGHT";
    chessBoard[0][1].color='B';
    chessBoard[0][1].file='B';
    chessBoard[0][1].rank=1;
    chessBoard[0][1].ifPresent=true;

    chessBoard[0][2].name="BISHOP";
    chessBoard[0][2].color='B';
    chessBoard[0][2].file='C';
    chessBoard[0][2].rank=1;
    chessBoard[0][2].ifPresent=true;

    chessBoard[0][3].name="QUEEN";
    chessBoard[0][3].color='B';
    chessBoard[0][3].file='D';
    chessBoard[0][3].rank=1;
    chessBoard[0][3].ifPresent=true;

    chessBoard[0][4].name="KING";
    chessBoard[0][4].color='B';
    chessBoard[0][4].file='E';
    chessBoard[0][4].rank=1;
    chessBoard[0][4].ifPresent=true;

    chessBoard[0][5].name="BISHOP";
    chessBoard[0][5].color='B';
    chessBoard[0][5].file='F';
    chessBoard[0][5].rank=1;
    chessBoard[0][5].ifPresent=true;

    chessBoard[0][6].name="KNIGHT";
    chessBoard[0][6].color='B';
    chessBoard[0][6].file='G';
    chessBoard[0][6].rank=1;
    chessBoard[0][6].ifPresent=true;

    chessBoard[0][7].name="ROOK";
    chessBoard[0][7].color='B';
    chessBoard[0][7].file='H';
    chessBoard[0][7].rank=1;
    chessBoard[0][7].ifPresent=true;


    for(int i=1;;){
        for(int j=0; j<8; j++){
            char temp = 65+j;
            chessBoard[i][j].name="PAWN";
            chessBoard[i][j].color='B';
            chessBoard[i][j].file=temp;
            chessBoard[i][j].rank=i;
            chessBoard[i][j].ifPresent=true;
        }
    }

    chessBoard[0][0].name="ROOK";
    chessBoard[0][0].color='B';
    chessBoard[0][0].file='A';
    chessBoard[0][0].rank=1;
    chessBoard[0][0].ifPresent=true;

    chessBoard[0][1].name="KNIGHT";
    chessBoard[0][1].color='B';
    chessBoard[0][1].file='B';
    chessBoard[0][1].rank=1;
    chessBoard[0][1].ifPresent=true;

    chessBoard[0][2].name="BISHOP";
    chessBoard[0][2].color='B';
    chessBoard[0][2].file='C';
    chessBoard[0][2].rank=1;
    chessBoard[0][2].ifPresent=true;

    chessBoard[0][3].name="QUEEN";
    chessBoard[0][3].color='B';
    chessBoard[0][3].file='D';
    chessBoard[0][3].rank=1;
    chessBoard[0][3].ifPresent=true;

    chessBoard[0][4].name="KING";
    chessBoard[0][4].color='B';
    chessBoard[0][4].file='E';
    chessBoard[0][4].rank=1;
    chessBoard[0][4].ifPresent=true;

    chessBoard[0][5].name="BISHOP";
    chessBoard[0][5].color='B';
    chessBoard[0][5].file='F';
    chessBoard[0][5].rank=1;
    chessBoard[0][5].ifPresent=true;

    chessBoard[0][6].name="KNIGHT";
    chessBoard[0][6].color='B';
    chessBoard[0][6].file='G';
    chessBoard[0][6].rank=1;
    chessBoard[0][6].ifPresent=true;

    chessBoard[0][7].name="ROOK";
    chessBoard[0][7].color='B';
    chessBoard[0][7].file='H';
    chessBoard[0][7].rank=1;
    chessBoard[0][7].ifPresent=true;


    for(int i=1;;){
        for(int j=0; j<8; j++){
            char temp = 65+j;
            chessBoard[i][j].name="PAWN";
            chessBoard[i][j].color='B';
            chessBoard[i][j].file=temp;
            chessBoard[i][j].rank=i;
            chessBoard[i][j].ifPresent=true;
        }
    }


}
