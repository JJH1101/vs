#include <stdio.h>
#include <string.h>

int main()
{
	char ary[5][16];
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", ary[i]);
	}
	char temp[16];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (strlen(ary[j]) > strlen(ary[j + 1]))
			{
				strcpy(temp, ary[j]);
				strcpy(ary[j], ary[j+1]);
				strcpy(ary[j+1], temp);
			}
			else if (strlen(ary[j]) == strlen(ary[j + 1]))
			{
				if (strcmp(ary[j], ary[j + 1]) == 1)
				{
					strcpy(temp, ary[j]);
					strcpy(ary[j], ary[j + 1]);
					strcpy(ary[j + 1], temp);
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", ary[i]);
	}
	return 0;
}