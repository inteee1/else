#include <stdio.h>
#include "board.h"

int main(void)
{
    int framescores[11] = {0, };
    int bonusCast;
    int scores[11][3] = {0, };
    printBoard();
    for (int i = 1; i <= 10; ++i ) {
        printf("%d frame first cast : ", i);
        scanf("%d", &scores[i][1]);
        setScore(i, 1, scores[i][1]);
        printBoard();
         //i frame 1st cast.
        if(i > 1 && scores[i-1][1] + scores[i-1][2] == 10 && scores[i-1][1] != 10)
        {
            int bonus = scores[i][1];
            framescores[i-1] = framescores[i-2] + 10 + bonus;
           //printf("frame : %d score : %d\n", i-1, framescores[i-1]);
            setFrameScore(i-1, framescores[i-1]);
            
        }
        else if(i > 2 && scores[i-2][1] == 10 && scores[i-1][1] == 10)
        {
            int bonus = scores[i-1][1] + scores[i][1];
            framescores[i-2] = framescores[i-3] + 10 + bonus;
            //printf("frame : %d score : %d\n", i-2, framescores[i-2]);
            setFrameScore(i-2, framescores[i-2]);
          }
          printBoard();
          //second cast (10 frame || 1~9 frame strike X)
        if(scores[i][1] != 10 && i != 10 || i == 10) {
            printf("%d frame second cast : ", i);
            scanf("%d", &scores[i][2]);
            setScore(i, 2, scores[i][2]);

            if(i > 1 && scores[i-1][1] == 10) {
                int bonus = (scores[i][1] + scores[i][2]);
                framescores[i-1] = framescores[i-2] + 10 + bonus;
                //printf("frame : %d score : %d\n", i-1, framescores[i-1]);
                setFrameScore(i-1, framescores[i-1]);
            }
            if(scores[i][1] + scores[i][2] < 10) {
                // 2) i frame 1st + 2nd < 10 --> i frame score!
                framescores[i] = framescores[i-1] + scores[i][1] + scores[i][2];
                // printf("frame : %d score : %d\n", i , framescores[i]);
                setFrameScore(i, framescores[i]);
            }
            printBoard();
        }

         if(i == 10 && scores[i][1] + scores[i][2] >= 10 ) {
                printf("%d frame thrid cast : ", i);
                scanf("%d", &bonusCast);
                setScore(10, 3, bonusCast);
                framescores[i] = framescores[i-1] + scores[i-1][1] + scores[i][2] + bonusCast;
                //printf("frame : 10 score : %d\n", framescores[i]);
                setFrameScore(i, framescores[i]);
                
                printBoard();
            }
            
    }
            
    return 0;
}