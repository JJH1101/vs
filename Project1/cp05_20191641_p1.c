#include <stdio.h>

void sort_all(int A[][3], int N)
{
	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2 - j; k++)
			{
				if (*(*(A + i) + k) > *(*(A + i) + k + 1))
				{
					temp = *(*(A + i) + k);
					*(*(A + i) + k) = *(*(A + i) + k + 1);
					*(*(A + i) + k + 1) = temp;
				}
			}
		}
	}
}

int main()
{
	int n;
	int A[100][3];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	sort_all(A, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}