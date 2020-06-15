# Chess
A console/terminal based game of Chess

-------------------------------------------------------------
                CONSOLE/TERMINAL BASED GAME OF
                           CHESS
-------------------------------------------------------------

BY:
Divij Jain
Github: jaindivij21

INTRODUCTION
This project is a simple chess engine i.e a console/command line C++ Chess program.
Chess is a two-player strategy board game played on a checkered board with 64 squares arranged in an 8×8 grid. It is a very popular and quite an old game,
filled with rules and alot of logic in order to ensure proper implementation.

FILES
This program has 2 files:
1) main.cpp
2) defs.h

The main program is in main.cpp while all the definations and the functions that mak eup the program reside in defs.h

EXCLUDED FEATURES
Below are a few complex features/functions that exist in chess but weren't included in this program for simplicity, but they can be added in future versions.

1) Stalemate
2) No castling
3) No en Passant
4) No double pawn move
5) No pawn promotion

WORKING

A) main.cpp
    This just starts the program by asking for the name of both the users and assigning them their choice of color. Then it calls the main function i.e. playGame() in defs.h
to initiate the game play.

B) defs.h
    This file is quite large and contains all the game funcitons.

    Basic elements:
        1. chessBoard[8][8]: an array of 8x8 is used for our 64 squared chess board where each square is represented by the combination of file and rank.
        2. struct piece: A structure has been created to represent each of those 64 squares of the chess board. It conatins all the properties essential for the working
                         of the program like ifPresent, name, color, file, and rank.

    Functions:
        1. playGame(): This function wraps up the entire game i.e. it is the main function. It calls the initializeBoard() function, runs the main game loop and
                       finally prints the game result.
        2. intializeBoard(): This function establishes the initial board for play i.e. sets up the pieces on the respective position when the game starts.
        3. printBoard(): This is an extensive function that uses multiple cout/print statements to make a chessboard using multiple characters '#' along with also printing
                         the respective piece positions.
        4. allowPlay(): This is the function called in the while loop condition of the main playGame() function. It is executed after every move to test if the game is over
                        or not. If it returns 1, it means the game is over. In total it checks for 3 conditions to decide if the game is over or not which are, if
                        total moves are more than 100 or not which are tracked using the variable totalMoves, if its check mate or is the king dead.
        5. move(): This funciton asks the user for piece movement and then executes a valid and legal move from one position on the checkBoard to another valid position.
        6. alternateTurn(): This funciton is executed after every move. Basically it alternated the turn between the 2 players.
        7. extractArrayPos(): This function is nothing but some logical statements to turn rank and file of chessBoard squares into array indexes.
        8. statusOfNewPos(): Its a part of move function while being used at other instances also. It's aim is to determine the status of position where
                             the player is moving its piece i.e. if its empty, has a piece of same color or has a piece of other color. Based of these the move is termed
                             valid or not.
        9. validityOfMove(): This is probably the most important function of the entire program as well as the most used one. It checks if the user isn't moving its piece
                             outside of the board and is the move legal in respect to the specific chess piece through another fucntion legalityOfMove().
        10. legalityOfMove(): This function consists of switch case and alot of if-else statement logic that basically determines piece specific logic regarding the movement
                              of these pieces. For eg. a bishop moves only diagnolly.
        11. isKingDead(): A fucntion called after every move through allowPlay() fucniton. It loops over the entire chessBoard to find both the kings. If it doesnt it stops
                          the game by returning false.
        12. isItCheckMate(): This funciton runs after every move under allowPlay() and checks if any player has been checkMate or not. If yes, the game ends otherwise it
                             continues. It incorporates many other sub functions like isItCheck(), canIntervene(), canKingMove(), canCut(). If its a check while all the
                             other functions return false; its a check mate.
        13. isItCheck(): This uses brute force to go over all the 64 squares and checks if any piece of a particular color can reach the king of other color, if yes, its a
                         check, other wise its not.
        14. canKingMove(): This is subfunction in isItCheckMate() and after a check has been established; it is used to determine if the king can move out of a check to
                           not lose the game through check mate.
        15. canIntervene(): This is subfunction in isItCheckMate() and after a check has been established; it is used to determine if some piece and come in between the king
                            and the piece that checked the king to escape check mate.
        16. canCut(): This is subfunction in isItCheckMate() and after a check has been established; it is used to determine if some piece can save the checked king by
                      taking down the piece that checked the king.
        17. checkAtSpecificPosition(): to check if its a check at a specific position.

EXTRAS
The source code is well commented and well formatted for ease of reading

CONCLUSION
This program replicates the chess engine very well and the time spent programming hass been very rewarding in terms of increasing my understanding. Hope you like it!
