#include <stdio.h>
#include <stdlib.h>

void sort(int* ary, int size)
{
	int temp;
	for(int i = 0; i < size; i++)
		for (int j = 0; j < size - 1 - i; j++)
			if (*(ary + j) > *(ary + j + 1))
			{
				temp = *(ary + j);
				*(ary + j) = *(ary + j + 1);
				*(ary + j + 1) = temp;
			}
}

void search(int* ary, int size, int target)
{
	int s = 0, r = size, m;
	while (1)
	{
		m = (s + r) / 2;
		if (*(ary + m) == target)
		{
			printf("%d\n", m);
			return;
		}
		if (s == r)
		{
			printf("-1\n");
			return;
		}
		if (*(ary + m) < target) s = m + 1;
		else r = m - 1;
	}
}

int main()
{
	char* C;
	int* I;
	int size = 1, target;
	C = (char*)calloc(10, sizeof(char));
	I = (int*)calloc(1, sizeof(int));
	int i;
	for (i = 0; ; i++)
	{
		scanf("%s", C);
		if (*C == 'q') break;
		if (i >= size)
		{
			size *= 2;
			I = (int*)realloc(I, size * sizeof(int));
		}
		*(I + i) = atoi(C);
	}
	scanf("%d", &target);
	sort(I, i);
	for (int j = 0; j < i; j++)
	{
		printf("%d ", *(I + j));
	}
	printf("\n");
	search(I, i - 1, target);
	free(C);
	free(I);
	return 0;
}