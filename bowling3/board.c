#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
// char *board[7] X
static char board[7][50] = {
    "--------------------------------------------",
    "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  10  |",
    "--------------------------------------------",
    "| | | | | | | | | | | | | | | | | | | | |  |",
    "--------------------------------------------",
    "|   |   |   |   |   |   |   |   |   |      |",
    "--------------------------------------------",
};   

void printBoard(void)
{
    system("clear");
    for (int i = 0; i < 7; ++i)
    {
        printf("%s\n", board[i]);
    }
}

void setScore(int frame, int cast, int score) 
{
    char c; 
    if ( cast != 1 && board[3][4 * (frame-1) + 1] - '0' + score == 10 ) {// spare 10 frame X 0 /
        c = '/';
        //spare
    } else if( cast == 1 && score == 10 || frame == 10 && score == 10){
        c ='X';
        //strike
    } else {
        c = score + '0';
        //일반
    }
    board[3][4 * (frame-1) + 2*cast-1] = c;
    
    // board[3][?] = [0 ~9] or '/', 'X' int score ----> char...???
}

void setFrameScore(int frame, int frameScore)
{
    char buf[10];
    sprintf(buf, "%3d", frameScore);
    strncpy(&board[5][0] + 4 * (frame -1) + 1, buf, 3);
    // board[5][???] <---- "%3d"
}
