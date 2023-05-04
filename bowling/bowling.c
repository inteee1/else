#include <stdio.h>

int T_score[1000];
int TT_score[1000] = {0, };
int strike_count = 0;
void strike(int *pa, int *pi, int *pscores)
{
    
    pscores[*pi] = *pa;
    T_score[*pi] = T_score[*pi-1] + pscores[*pi];
    if(*pi > 2 && pscores[*pi-1] == 10 && pscores[*pi-2])
     { 
        TT_score[*pi-2] = TT_score[*pi-3] + T_score[*pi];
        T_score[*pi] = T_score[*pi] - pscores[*pi-2];
        
        printf("frame : %d score : %d\n", *pi-2, TT_score[*pi-2]);
     }
    
}

int spare(int *pa, int *pb, int *pi, int *pscores)
{
    
    pscores[0] = 0;
    T_score[0] = 0;
    int c;
   
    for(int j = 1; j <= *pi; ++j)
    {
        if(*pi == 10){
            pscores[j] = *pa + *pb;
            printf("%d frame thrid cast : ", *pi);
            scanf("%d", &c);
            T_score[j] = pscores[j] + c;
        }
        else{
        pscores[j] = *pa + *pb;
        printf("%d frame first cast : ", *pi+1);
        scanf("%d", &c);
        T_score[j] = pscores[j] + c;
        }
    }
    if (*pi > 10){

        printf("frame : 10 score : %d\n", T_score[*pi]);
    } else {
        printf("frame : %d score : %d\n", *pi, T_score[*pi]);
    }
    return c;
}

void common(int *pa, int *pb, int *pi, int *pscores)
{
    T_score[0] = 0;
    pscores[0] = 0;
    for(int j = 1; j <= *pi; ++j)
    {
        pscores[j] = *pa + *pb;
        T_score[j] = T_score[j-1]+ pscores[j];
         
    }
    printf("frame : %d score : %d\n", *pi, T_score[*pi]);
   
}

 



int main(void)
{
    int scores[1000];
    int a, b, i;
    int spare_count = 1;
    
    for(i= 1; i <= 10; ++i) {
        if (i == 10) {
            if(spare_count == 1)
            {   
                printf("%d frame first cast : ", i);
                scanf("%d", &a);
            } else {
                ++spare_count;
                a = 0;
            }

        
            if(a != 10) {
                printf("%d frame second cast : ", i);
                scanf("%d", &b);
                if((a + b) != 10) {
                common(&a, &b, &i, scores);
               
                } else //스페어
                    {
                        spare(&a, &b, &i, scores);
                        --spare_count;
                    }
            
            }else { // 스트라이크
                 strike(&a, &i, scores); 
                 printf("%d frame second cast: ", i);
                 scanf("%d", &a);
                 if(a == 10) {
                    ++i;
                    strike(&a, &i, scores);
                    printf("10 frame thrid cast: " );
                    scanf("%d", &a);
                    if (a == 10) {
                        ++i;
                        strike(&a, &i,scores);
                    }
                    else {
                        printf("frame : 10 score : %d", TT_score[9] + a);
                    }
                        
                  }
                    
                 }
                }
    else{
        if(spare_count == 1)
        {   
            printf("%d frame first cast : ", i);
            scanf("%d", &a);
        } else {
            ++spare_count;
           a = 0;
        }

        
        if(a != 10) {
            printf("%d frame second cast : ", i);
            scanf("%d", &b);
            if((a + b) != 10) {
               common(&a, &b, &i, scores);
               
            } else //스페어
                {
                    spare(&a, &b, &i, scores);
                    --spare_count;
                    }
            
        }else { // 스트라이크
             strike(&a, &i, scores); 
    }
    

        }
    } 
 }



