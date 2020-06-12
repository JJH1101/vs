#include <stdio.h>
#include <string.h>

typedef struct
{
	int i;
	char s[10];
	float f;
}st;

int main()
{
	st input, output;
	
	scanf("%d %s %f", &input.i, input.s, &input.f);
	output = input;
	printf("%d %s %f", output.i, output.s, output.f);
	
	return 0;
}