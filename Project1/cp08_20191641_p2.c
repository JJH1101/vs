#include <stdio.h>
#include <stdlib.h>

int alloc;

void* my_malloc(size_t Size)
{
	alloc = Size;
	malloc(Size);
}

int main()
{
	int n;
	scanf("%d", &n);
	int size = 0;
	for (int i = 1; i <= n; i++)
		size += i;
	int* pascal_tr[30];
	int* ary;
	ary = my_malloc(size * sizeof(int));
	size = 0;
	for (int i = 0; i < n; i++)
	{
		size += i;
		pascal_tr[i] = ary + size;
	}
	for (int i = 0; i < n; i++)
	{
		pascal_tr[i][0] = 1;
		pascal_tr[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			pascal_tr[i][j] = pascal_tr[i - 1][j] + pascal_tr[i - 1][j - 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", pascal_tr[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", alloc);
	free(ary);
	return 0;
}