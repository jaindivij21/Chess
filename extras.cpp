#include <cstdio>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include "defs.h"



bool canMove(char color);


// checks for other person's pieces i.e if they can move anywhere or not
bool canMove(char color)
{

    // for each piece of specific color
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if ((chessBoard[i][j].ifPresent == true) && (chessBoard[i][j].color = color)) // if piece found
            {
                // check if the found piece can move somewhere
                for (int m = 0; m < 7; m++)
                {
                    for (int n = 0; n < 7; n++)
                    {
                        int extractedRank = i + 1;
                        char extractedFile = j + 65;
                        if (validityOfMove(m, n, extractedRank, extractedFile) && statusOfNewPos(m, n, extractedRank, extractedFile))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

//check for stale mate
bool isItStaleMate()
{   
    if (!canMove(whatColour)) //  white piece has no move possible
    {
        cout << "Its a Stale Mate!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}