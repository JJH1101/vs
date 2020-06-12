#include <stdio.h>
#include <string.h>

void delete_char(char* arr, char ch)
{
	int size;
	size = strlen(arr) + 1;
	int r = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == ch)
		{
			r = 1;
			for (int j = i; j < size - 1; j++)
			{
				*(arr + j) = *(arr + j + 1);
			}
		}
	}
	if (r == 1)
		printf("%s\n", arr);
	else
		printf("Not Found\n");
}

int main()
{
	char arr[10], ch;
	scanf("%s\n", arr);
	scanf("%c", &ch);
	delete_char(arr, ch);
	return 0;
}