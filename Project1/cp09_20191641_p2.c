#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strstr(char* origin, char* pattern)
{
	for (int i = 0; i < strlen(origin); i++)
	{
		if (*(origin + i) == *pattern)
		{
			int j;
			for (j = 0; j < strlen(pattern); j++)
			{
				if (*(origin + i + j) != *(pattern + j))
				{
					break;
				}
			}
			if (j == strlen(pattern))
				return i;
		}
	}
	return -1;
}

int main()
{
	char* origin, *pattern;
	origin = (char*)malloc(11 * sizeof(char));
	pattern = (char*)malloc(11 * sizeof(char));
	scanf("%s %s", origin, pattern);
	printf("%d\n", my_strstr(origin, pattern));
	free(origin);
	free(pattern);
	return 0;
}