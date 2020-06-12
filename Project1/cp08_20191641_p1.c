#include <stdio.h>
#include <stdlib.h>


int main()
{
	int p, r, c;
	scanf("%d %d %d", &p, &r, &c);
	int*** ary;
	ary = (int***)malloc(p * sizeof(int));
	for (int i = 0; i < p; i++)
		ary[i] = (int**)malloc(r * sizeof(int));
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
			ary[i][j] = (int*)malloc(c * sizeof(int));
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				*(*(*(ary+i)+j)+k) = k + j * c + i * c * r;
			}
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				printf("%d ", *(*(*(ary + i) + j) + k));
			}
			printf("\n");
		}
		printf("\n");
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
			free(ary[i][j]);
	}
	for (int i = 0; i < p; i++)
		free(ary[i]);
	free(ary);
	return 0;
}