#include <stdio.h>
#include <stdlib.h>

int** mulMatrix(int a[][3], int b[][4], int num1, int num2)
{
	int** result;
	result = (int**)malloc(num1 * sizeof(int*));
	for (int i = 0; i < num1; i++)
		result[i] = (int*)malloc(num2 * sizeof(int));

	for (int i = 0; i < num1; i++)
		for (int j = 0; j < num2; j++)
			result[i][j] = 0;

	for (int i = 0; i < num1; i++)
		for (int j = 0; j < num2; j++)
			for (int k = 0; k < num1; k++)
				result[i][j] = result[i][j] + a[i][k] * b[k][j];

	return result;
}

void main()

{

	int i, j;

	int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	int b[3][4] = { {1, 4, 7, 10}, {2, 5, 8, 11}, {3, 6, 9, 12} };

	int** result;

	for (i = 0; i < 3; i++)

	{

		for (j = 0; j < 3; j++)

		{

			printf("%d ", a[i][j]);

		}

		printf("\n");

	}

	printf("\n");

	for (i = 0; i < 3; i++)

	{

		for (j = 0; j < 4; j++)

		{

			printf("%d ", b[i][j]);

		}

		printf("\n");

	}

	printf("\n");

	result = mulMatrix(a, b, 3, 4);

	for (i = 0; i < 3; i++)

	{

		for (j = 0; j < 4; j++)

		{

			printf("%d ", result[i][j]);

		}

		printf("\n");

	}

	return 0;
}