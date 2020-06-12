#include <stdio.h>

void Adder(void* num1, void* num2, char option)
{
	if (option == 'i')
	{
		printf("%d", *(int*)num1 + *(int*)num2);
	}
	else if (option == 'd')
	{
		printf("%.6lf", *(double*)num1 + *(double*)num2);
	}
}

int main()
{
	char op;
	scanf("%c", &op);
	if (op == 'i')
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		Adder(&num1, &num2, op);
	}
	else if (op == 'd')
	{
		double num1, num2;
		scanf("%lf %lf", &num1, &num2);
		Adder(&num1, &num2, op);
	}
	return 0;
}