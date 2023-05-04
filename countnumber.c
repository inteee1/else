#include <stdio.h>

int main(void)
{
	int N = 0;
	int array[999];
	int count = 0;
	int find;
	
	scanf("%d", &N);
	for(int i = 0; i < N ; ++i)
	{
		scanf("%d", &array[i]);
	}
	scanf("%d", &find);
	for(int j = 0; j < N ; ++j)
	{
		if(array[j] == find)
		{ ++count;}
		
	}
	printf("%d\n", count);
	return 0;
}
