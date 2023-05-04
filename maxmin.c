#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int array[100];
    for(int i= 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
    }
    int max = array[0];
    int min = array[0];
    for (int j = 0; j < n; ++j)
    {
        if (array[j] < min) {
            min = array[j];
        }
        if (array[j] > max) {
            max = array[j];
        }

    }
    printf("max : %d, min : %d\n", max, min);
    return 0;
}