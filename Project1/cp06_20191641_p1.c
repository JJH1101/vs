#include <stdio.h>
#include <stdlib.h>

int* calculate_next(int* pascal_tr, int current_level)
{
	int* next_level;
	next_level = (int*)malloc((current_level + 1) * sizeof(int));
	*next_level = 1;
	*(next_level + current_level) = 1;
	for (int i = 1; i < current_level; i++)
		*(next_level + i) = *(pascal_tr + i) + *(pascal_tr + i - 1);
	return next_level;
}

int main()
{
	int level;
	int* pascal_tr;
	scanf("%d", &level);
	pascal_tr = (int*)malloc(level * sizeof(int));
	for (int i = 0; i < level; i++)
	{
		pascal_tr = calculate_next(pascal_tr, i);
		for (int j = 0; j <= i; j++)
			printf("%d ", *(pascal_tr + j));
		printf("\n");
	}
	free(pascal_tr);
	return 0;
}