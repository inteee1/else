#include <stdio.h>

int main(void)
{
    int n, m;
    int nums[101] = {0, };
    int a, b, c;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        for(int j = a; j <= b; ++j)
        {
            nums[j] = c;
        }
    }
    for (int i = 0; i <= n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}