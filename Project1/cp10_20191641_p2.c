#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_sort(char* str)
{
	char temp;
	for (int i = 0; i < strlen(str); i++)
	{
		for (int j = 0; j < strlen(str) - 1 - i; j++)
		{
			if ((int)*(str + j) > (int)*(str + j + 1))
			{
				temp = *(str + j);
				*(str + j) = *(str + j + 1);
				*(str + j + 1) = temp;
			}
		}
	}
}

int main()
{
	char* str1, *str2, *str3;
	str1 = (char*)malloc(16 * sizeof(char));
	str2 = (char*)malloc(16 * sizeof(char));
	scanf("%s", str1);
	scanf("%s", str2);
	printf("%s\n", str1);
	printf("%s\n", str2);
	str3 = (char*)malloc((strlen(str1) + strlen(str2) +	1) * sizeof(int));
	for (int i = 0; i < strlen(str1); i++)
	{
		*(str3 + i) = *(str1 + i);
	}
	for (int i = 0; i <= strlen(str2); i++)
	{
		*(str3 + strlen(str1) + i) = *(str2 + i);
	}
	printf("%s\n", str3);
	str_sort(str3);
	printf("%s\n", str3);
	free(str1);
	free(str2);
	free(str3);
	return 0;
}