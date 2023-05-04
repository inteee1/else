#include <stdio.h>

int main(void)
{
    int scores[11][3];
    int bonusCast;
     int framescores[11] = {0, };

    for (int i = 1; i <= 10; ++i) {
        // first cast
        printf("%d frame first cast : ", i);
        scanf("%d", &scores[i][1]);
         
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
        if(scores[9][1] + scores[9][2] == 10 && scores[9][1] != 10)
        {
            framescores[9] = framescores[8] + 10 + scores[9][1];
            printf("frame : 9 score : %d\n", framescores[9]);
        }
    
        else if(scores[8][1] == 10 && scores[9][1] == 10)
        {
            int bonus = (10 + scores[10][1]);
            framescores[8] = framescores[7] + 10 + bonus;
            printf("frame : 8 score : %d\n", framescores[8]);
        }
        //second (10 frame || 1~9 frame strike X)
        if(scores[i][1] != 10) {
            printf("%d frame second cast : ", i);
            scanf("%d", &scores[i][2]);
            if(i > 1 && scores[i-1][1] == 10) {
                int bonus = (scores[i][1] + scores[i][2]);
                framescores[i-1] = framescores[i-2] + 10 + bonus;
                printf("frame : %d score : %d\n", i-1, framescores[i-1]);
            }
            if(scores[i][1] + scores[i][2] < 10) {
                    framescores[i] = framescores[i-1] + scores[i][1] + scores[i][2];
                    printf("frame : %d score : %d\n", i , framescores[i]);
            }
        }
         // 10frame bonus cast. ???

        if(scores[9][1] == 10) {
                    
                framescores[9] = framescores[8] + 10 + scores[10][1] + scores[10][2];
                printf("frame : 9 score : %d\n", framescores[9]);
            }
            if((scores[10][1] + scores[10][2]) < 10) {
                
                framescores[10] = framescores[9] + scores[10][1] + scores[10][2];
                printf("frame : 10 score : %d\n", framescores[10]);
            } else {
                printf("10 frame thrid cast : ");
                scanf("%d", &scores[10][3]);
                framescores[10] = framescores[9] + scores[10][1] + scores[10][2] + scores[10][3];
                printf("frame : 10 score : %d\n", framescores[10]);
            }
       

    }


    return 0;
}
