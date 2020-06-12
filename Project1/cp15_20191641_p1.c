#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char *str1;
	char *str2;
	char *str3;
} firstString;

typedef struct
{
	char *str1;
	char *str2;
	char *str3;
} secondString;

int main()
{
	firstString first;
	first.str1 = (char*)malloc(4 * sizeof(char));
	first.str2 = (char*)malloc(4 * sizeof(char));
	first.str3 = (char*)malloc(6 * sizeof(char));
	strcpy(first.str1, "one");
	strcpy(first.str2, "two");
	strcpy(first.str3, "three");

	secondString second;
	second.str1 = (char*)malloc(4 * sizeof(char));
	second.str2 = (char*)malloc(4 * sizeof(char));
	second.str3 = (char*)malloc(6 * sizeof(char));
	strcpy(second.str1, "one");
	strcpy(second.str2, "two");
	strcpy(second.str3, "three");

	char temp1[9], temp2[6];

	int a, b;
	scanf("%d %d", &a, &b);

	if (a == 1)
		strcpy(temp1, first.str1);
	else if (a == 2)
		strcpy(temp1, first.str2);
	else if (a == 3)
		strcpy(temp1, first.str3);

	if (b == 1)
		strcpy(temp2, second.str1);
	else if (b == 2)
		strcpy(temp2, second.str2);
	else if (b == 3)
		strcpy(temp2, second.str3);

	strcat(temp1, temp2);
	
	printf("%s\n", temp1);

	free(first.str1);
	free(first.str2);
	free(first.str3);
	free(second.str1);
	free(second.str2);
	free(second.str3);

	return 0;
}