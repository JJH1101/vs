#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum {
	INTEGER = 0, REAL, NAN
}Type;

typedef struct __Number {
	Type t;
	union {
		int i;
		double r;
	}data;
}Number;

typedef enum {
	ADD = 0, SUB, MUL, DIV
}Operation;

Number calculate(Number n1, Number n2, Operation op)
{
	Number result;
	switch (op)
	{
	case ADD:
		if (n1.t == INTEGER && n2.t == INTEGER)
		{
			result.t = INTEGER;
			result.data.i = n1.data.i + n2.data.i;
		}
		else if(n1.t == INTEGER && n2.t == REAL)
		{
			result.t = REAL;
			result.data.r = n1.data.i + n2.data.r;
		}
		else if (n1.t == REAL && n2.t == INTEGER)
		{
			result.t = REAL;
			result.data.r = n1.data.r + n2.data.i;
		}
		else
		{
			result.t = REAL;
			result.data.r = n1.data.r + n2.data.r;
		}
		break;

	case SUB:
		if (n1.t == INTEGER && n2.t == INTEGER)
		{
			result.t = INTEGER;
			result.data.i = n1.data.i - n2.data.i;
		}
		else if (n1.t == INTEGER && n2.t == REAL)
		{
			result.t = REAL;
			result.data.r = n1.data.i - n2.data.r;
		}
		else if (n1.t == REAL && n2.t == INTEGER)
		{
			result.t = REAL;
			result.data.r = n1.data.r - n2.data.i;
		}
		else
		{
			result.t = REAL;
			result.data.r = n1.data.r - n2.data.r;
		}
		break;

	case MUL:
		if (n1.t == INTEGER && n2.t == INTEGER)
		{
			result.t = INTEGER;
			result.data.i = n1.data.i * n2.data.i;
		}
		else if (n1.t == INTEGER && n2.t == REAL)
		{
			result.t = REAL;
			result.data.r = n1.data.i * n2.data.r;
		}
		else if (n1.t == REAL && n2.t == INTEGER)
		{
			result.t = REAL;
			result.data.r = n1.data.r * n2.data.i;
		}
		else
		{
			result.t = REAL;
			result.data.r = n1.data.r * n2.data.r;
		}
		break;

	case DIV:
		if (n2.data.i == 0 || n2.data.r == 0)
			result.t = NAN;
		else if (n1.t == INTEGER && n2.t == INTEGER)
		{
			result.t = REAL;
			result.data.r = n1.data.i / n2.data.i;
		}
		else if (n1.t == INTEGER && n2.t == REAL)
		{
			result.t = REAL;
			result.data.r = n1.data.i / n2.data.r;
		}
		else if (n1.t == REAL && n2.t == INTEGER)
		{
			result.t = REAL;
			result.data.r = n1.data.r / n2.data.i;
		}
		else
		{
			result.t = REAL;
			result.data.r = n1.data.r / n2.data.r;
		}
		break;

	default:
		break;
	}

	return result;
}

int main()
{
	Number n1, n2, result;
	char num1[30], num2[30];

	scanf("%s %s", num1, num2);

	int i;
	for (i = 0; i < strlen(num1); i++)
	{
		if (num1[i] == '.') break;
	}
	if (i == strlen(num1))
	{
		n1.t = INTEGER;
		n1.data.i = atoi(num1);
	}
	else
	{
		n1.t = REAL;
		n1.data.r = atof(num1);
	}

	for (i = 0; i < strlen(num2); i++)
	{
		if (num2[i] == '.') break;
	}
	if (i == strlen(num2))
	{
		n2.t = INTEGER;
		n2.data.i = atoi(num2);
	}
	else
	{
		n2.t = REAL;
		n2.data.r = atof(num2);
	}

	result = calculate(n1, n2, ADD);
	if (result.t == INTEGER)
		printf("ADD %d INTEGER\n", result.data.i);
	else
		printf("ADD %f REAL\n", result.data.r);

	result = calculate(n1, n2, SUB);
	if (result.t == INTEGER)
		printf("SUB %d INTEGER\n", result.data.i);
	else
		printf("SUB %f REAL\n", result.data.r);

	result = calculate(n1, n2, MUL);
	if (result.t == INTEGER)
		printf("MUL %d INTEGER\n", result.data.i);
	else
		printf("MUL %f REAL\n", result.data.r);

	result = calculate(n1, n2, DIV);
	if (result.t == REAL)
		printf("DIV %f REAL\n", result.data.r);
	else
		printf("DIV NAN");

	return 0;
}