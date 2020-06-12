#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool freePrint(char str[], int strSize, FILE* fp)
{
	fputs(str, stdout);
	fputs(str, fp);
}

int main()
{
	FILE* fp;
	fp = fopen("output.txt", "w");
	int N;
	char* str;
	scanf("%d\n", &N);
	str = (char*)malloc((N + 2) * sizeof(char));
	fgets(str, N + 1, stdin);
	freePrint(str, strlen(str), fp);
	free(str);
	fclose(fp);
	return 0;
}