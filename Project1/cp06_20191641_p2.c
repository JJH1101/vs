#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copy_str(char* dest, char* src)
{
	int size;
	size = strlen(src) + 1;
	for (int i = 0; i < size; i++)
	{
		*(dest + i) = *(src + i);
	}
}

int main()
{
	char src[11];
	char* dest;
	scanf("%[^\n]s", src);
	int size;
	size = strlen(src) + 1;
	dest = (char*)malloc(size * sizeof(char));
	copy_str(dest, src);
	printf("%s\n", dest);
	free(dest);
	free(src);
	return 0;
}