#include <stdio.h>
#include <stdlib.h>

int main()
{
	int p, r, c;
	scanf("%d %d %d", &p, &r, &c);
	int* A;
	int* ary[10][10];
	A = (int*)malloc(p * r * c * sizeof(int));
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				ary[i][j] = A + k + j * c + i * c * r;
			}
		}
	}

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				ary[i][j][k] = k + j * c + i * c * r;
			}
		}
	}
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				printf("%d ", ary[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	free(A);
	return 0;
}