#include <stdio.h>
#include <string.h>

int my_atoi(const char* str)
{
	int n = 0;
	float digit = 0.1;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		digit *= 10;
		n = n + ((int)str[i] - (int)'0')*(int)digit;
	}
	return n;
}

int main()
{
	char str[10];
	scanf("%s", str);
	printf("%d\n", my_atoi(str));
	return 0;
}
