#include <stdio.h>


int arr[101] = {0, };
void swap(int *pa, int *pb)
{
	
	int tmp = arr[*pa];
	arr[*pa] = arr[*pb];
	arr[*pb] = tmp;
}

int main(void)
{
	int m, n;
	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < n; ++i)  {
		arr[i] = i;
	}
	for( int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		swap(&a, &b);
	}
	for( int i = 0; i <= n ; ++i) {
		printf("%d", arr[i]);
	}
	return 0;
}
