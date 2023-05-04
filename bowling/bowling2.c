#include <stdio.h>

int main(void)
{
    int framescores[11] = {0, };
    
    
    // 1~9frame
    int scores[10][3] = {0, };
    for (int i = 1; i <= 9; ++i ) {
        printf("%d frame first cast : ", i);
        scanf("%d", &scores[i][1]);
         //i frame 1st cast.
        if(i > 1 && scores[i-1][1] + scores[i-1][2] == 10 && scores[i-1][1] != 10)
        {
            int bonus = scores[i][1];
            framescores[i-1] = framescores[i-2] + 10 + bonus;
            printf("frame : %d score : %d\n", i-1, framescores[i-1]);
        }
    //1) i-1 frame spare --> i-1 frame score !
        else if(i > 2 && scores[i-2][1] == 10 && scores[i-1][1] == 10)
        {
            int bonus = scores[i-1][1]/*10*/ + scores[i][1];
            framescores[i-2] = framescores[i-3] + 10 + bonus;
            printf("frame : %d score : %d\n", i-2, framescores[i-2]);
      
    //2) i-2 frame X and i-1 frame X --> i-2 frame score!
          }
        if(scores[i][1] != 10) {
              // if iframe first cast != 10 -> i frame 2nd cast
        
            printf("%d frame second cast : ", i);
            scanf("%d", &scores[i][2]);
            if(i > 1 && scores[i-1][1] == 10) {
                    // 1) i-1 frame X --> i-1 frame score !
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

  

    
    }
    //10 frame
    int scores10[4] = {0, };
    printf("10 frame first cast : ");
    scanf("%d", &scores10[1]);
    if(scores[9][1] + scores[9][2] == 10 && scores[9][1] != 10)
        {
            framescores[9] = framescores[8] + 10 + scores[9][1];
            printf("frame : 9 score : %d\n", framescores[9]);
        }
    
        else if(scores[8][1] == 10 && scores[9][1] == 10)
        {
            int bonus = (10 + scores10[1]);
            framescores[8] = framescores[7] + 10 + bonus;
            printf("frame : 8 score : %d\n", framescores[8]);
        }
      
        printf("10 frame second cast : ");
        scanf("%d", &scores10[2]);
            if(scores[9][1] == 10) {
                    
                framescores[9] = framescores[8] + 10 + scores10[1] + scores10[2];
                printf("frame : 9 score : %d\n", framescores[9]);
            }
            if((scores10[1] + scores10[2]) < 10) {
                
                framescores[10] = framescores[9] + scores10[1] + scores10[2];
                printf("frame : 10 score : %d\n", framescores[10]);
            } else {
                printf("10 frame thrid cast : ");
                scanf("%d", &scores10[3]);
                framescores[10] = framescores[9] + scores10[1] + scores10[2] + scores10[3];
                printf("frame : 10 score : %d\n", framescores[10]);
            }

            
    return 0;
}