#include <stdio.h>

int main(void)
{
    int framescores[11] = {0, };
    int bonusCast;
    int scores[11][3] = {0, };
    for (int i = 1; i <= 10; ++i ) {
        printf("%d frame first cast : ", i);
        scanf("%d", &scores[i][1]);
         //i frame 1st cast.
        if(i > 1 && scores[i-1][1] + scores[i-1][2] == 10 && scores[i-1][1] != 10)
        {
            int bonus = scores[i][1];
            framescores[i-1] = framescores[i-2] + 10 + bonus;
            printf("frame : %d score : %d\n", i-1, framescores[i-1]);
        }
        else if(i > 2 && scores[i-2][1] == 10 && scores[i-1][1] == 10)
        {
            int bonus = scores[i-1][1] + scores[i][1];
            framescores[i-2] = framescores[i-3] + 10 + bonus;
            printf("frame : %d score : %d\n", i-2, framescores[i-2]);
      
          }
          //second cast (10 frame || 1~9 frame strike X)
        if(scores[i][1] != 10 && i != 10 || i == 10) {
            printf("%d frame second cast : ", i);
            scanf("%d", &scores[i][2]);

            if(i > 1 && scores[i-1][1] == 10) {
                int bonus = (scores[i][1] + scores[i][2]);
                framescores[i-1] = framescores[i-2] + 10 + bonus;
                printf("frame : %d score : %d\n", i-1, framescores[i-1]);
            }
            if(scores[i][1] + scores[i][2] < 10) {
                // 2) i frame 1st + 2nd < 10 --> i frame score!
                        framescores[i] = framescores[i-1] + scores[i][1] + scores[i][2];
                        printf("frame : %d score : %d\n", i , framescores[i]);
            }
        }

         if(i == 10 && scores[i][1] + scores[i][2] >= 10 ) {
                printf("%d frame thrid cast : ", i);
                scanf("%d", &bonusCast);
                framescores[i] = framescores[i-1] + scores[i-1][1] + scores[i][2] + bonusCast;
                printf("frame : 10 score : %d\n", framescores[10]);
            }
    }
            
    return 0;
}