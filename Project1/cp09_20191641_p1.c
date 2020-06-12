#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flip_and_return(char* origin, int x, int y)
{
	char* result;
	result = (char*)malloc(11 * sizeof(char));
	for (int i = 0; i <= y - x; i++)
	{
		*(result + i) = *(origin + y - i);
	}
	*(result + y - x + 1) = '\0';
	return result;
}

int main()
{
	int x, y;
	char* input;
	char* output;
	input = (char*)malloc(11 * sizeof(char));
	scanf("%s %d %d", input, &x, &y);
	output = flip_and_return(input, x, y);
	printf("%s\n", output);
	free(input);
	free(output);
	return 0;
}