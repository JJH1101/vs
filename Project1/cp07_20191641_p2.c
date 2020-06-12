#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M;
	scanf("%d\n", &N);
	char* key;
	int* value;
	key = (char*)malloc(N * sizeof(char));
	value = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		char line[128];
		fgets(line, 128, stdin);
		sscanf(line, "%c%d", key + i, value + i);
	}
	scanf("%d\n", &M);
	char k;
	for (int i = 0; i < M; i++)
	{
		char line[128];
		fgets(line, 128, stdin);
		sscanf(line, "%c", &k);
		int j;
		for (j = 0; j < N; j++)
		{
			if (*(key + j) == k)
			{
				printf("%d\n", *(value + j));
				break;
			}
		}
		if (*(key + j) != k) printf("Not Found\n");
	}
	free(key);
	free(value);
	return 0;
}