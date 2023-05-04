#include <stdio.h>

int main(void)
{
	int N = 0;
	int array[999];
	int big_num = 0;
	
	
	scanf("%d, %d", &N, &big_num);
	for(int i = 0; i < N ; ++i)
	{
		scanf("%d", &array[i]);
	}
	
	for(int j = 0; j < N ; ++j)
	{
		if(array[j] <= big_num){
		
		printf("%d\n", array[j]);
		}
	}
	
	return 0;
}
