#include <stdio.h>

void sum_array(int *A, int *B, int *C, int size)
{
	for (int i = 0; i < size; i++)
		*(C + i) = *(A + i) + *(B + i);
}

int main()
{
	int n;
	int ary[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sum_array(ary, ary + 1, ary + 1, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");
	return 0;
}