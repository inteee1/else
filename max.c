#include <stdio.h>

int main(void)
{
	int n;
	int max = 0;
	int index;

	for (int i = 1; i < 9; ++i) {
		scanf("%d\n", &n);
		if (max < n){
		max = n;
		index = i;
		}
	}
	printf("max : %d, index : %d\n", max, index);
	return 0;
}
