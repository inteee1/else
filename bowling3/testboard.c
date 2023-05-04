#include <stdio.h>
#include "board.h"

int main(void)
{
    printBoard();
    for(int j = 1; j <= *pi; ++j) {
    setScore(j, 1, score[j][1]);
    setScore(j, 2, score[j][2]);
    setFrameScore(j, framescores[j]);
 
    printBoard();
    }
    return 0;
}