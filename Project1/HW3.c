#include <stdio.h>

int main()
{
	FILE* in = fopen("arrays.txt", "r");
	FILE* out = fopen("mulMatrix.txt", "w");

	int arr1[3][3], arr2[3][4], result[3][4];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			fscanf(in, "%d", &arr1[i][j]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			fscanf(in, "%d", &arr2[i][j]);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			result[i][j] = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
				result[i][j] = result[i][j] + arr1[i][k] * arr2[k][j];

	printf("mulMatrix.txt is created");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fprintf(out, "%d ", result[i][j]);
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}
