#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//dynamic allocated array that stores string user enters.
	char* line;
	line = (char*)malloc(128 * sizeof(char));

	//dynamic allocated 2D array that stores names of variables.
	char** name;
	name = (char**)malloc(32 * sizeof(char*));
	for (int i = 0; i < 32; i++)
		name[i] = (char*)malloc(31 * sizeof(char));

	//dynamic allocated array that stores name of command.
	char* com;
	com = (char*)malloc(11 * sizeof(char));

	double val; //variable that stores variable's value.

	//dynamic allocated array that stores each variable's value.
	int* value;
	value = (int*)malloc(32 * sizeof(int));

	//dynamic allocated arrays that store names of variables when user wants to use operators or print.
	char *var1, *var2;
	var1 = (char*)malloc(31 * sizeof(char));
	var2 = (char*)malloc(31 * sizeof(char));

	int num1, num2; //variables that store values of var1 and var2.

	/* op is variable that stores name of operator.
	check is variable for check if there is input string more than format. */
	char op,check;

	int i = 0, j = 0; // these variables are used in loop.

	for( ; ; )
	{
		printf(">> ");
		fgets(line, 128, stdin); //store input string in 'line' until user presses Enter.

		sscanf(line, "%s", com); //store string before space or enter in 'com'.

		/* when user enters "EXIT", exit program. 
		if user enters "EXIT" as well as anything else, print "error\n" */
		if (strcmp(com, "EXIT") == 0)
		{
			if (sscanf(line, "%s %c", com, &check) == 1) break; // use variable 'check' for check if there is input string more than format.
			else printf("error\n");
		}
		
		/* when user enters "INT {variable name} {integer value}", store variable name in name[i], store integer value in value[i], and increase value of 'i' by one.
		if user enters more than or less than the format(INT {variable name} {integer value}), print "error\n".
		if user enters something other than the alphabet in the {variable name}, print "error\n".
		if user enters something other than integer value in the {integer value}, print "error\n". */
		else if (strcmp(com, "INT") == 0)
		{
			if (sscanf(line, "%s %s %lf %c", com, name[i], &val, &check) == 3)
			{
				for (j = 0; j < strlen(name[i]); j++)
				{
					if (name[i][j] < 'A' || name[i][j] > 'z')
						break;
					else if ('Z' < name[i][j] && name[i][j] < 'a')
						break;
				}

				if (j == strlen(name[i]))
				{
					if (val == (int)val)
					{
						value[i] = (int)val;
						i++;
					}
					else printf("error\n");
				}
				else printf("error\n");
			}
			else printf("error\n");
		}

		/* when user enters "PRINT {varname}", find {varname} in array 'name' and if there is {varname} in 'name[index]' print "value[index]\n". 
		if there is not {varname} in array 'name', print "not found\n".
		if user enters more than or less than the format(PRINT {varname}), print "error\n". */
		else if (strcmp(com, "PRINT") == 0)
		{
			if (sscanf(line, "%s %s %c", com, var1, &check) == 2)
			{
				for (j = 0; j < i; j++)
				{
					if (strcmp(var1, name[j]) == 0)
					{
						printf("%d\n", value[j]);
						break;
					}
				}
				if (i == j) printf("not found\n");
			}
			else printf("error\n");
		}

		/* when user enters "PRINT_VARS", print the names of all stored variables in 'name', and theirs value that stored in 'value'.
		if there is no stored variable(i is 0), print "empty\n".
		if user enters "PRINT_VARS" as well as anything else, print "error\n" */
		else if (strcmp(com, "PRINT_VARS") == 0)
		{
			if (sscanf(line, "%s %c", com, &check) == 1)
			{
				if (i == 0) printf("empty\n");
				else
				{
					for (j = 0; j < i; j++)
					{
						printf("%s=%d\n", name[j], value[j]);
					}
				}
			}
			else printf("error\n");
		}

		else //if 'com' is not "EXIT", "INT", "PRINT", or "PRINT_VARS"
		{
			/* when user enters "{varname1} {operator} {varname2}", store varname1 in 'var1', varname2 in 'var2', operator in 'op'
			if user enters more than or less than the format({varname1} {operator} {varname2}), print "error\n".*/
			if (sscanf(line, "%s %c %s %c", var1, &op, var2, &check) == 3)
			{

				/* if var1[0] is '-' or number, check if var1 is number or not.
				if var1 is number, store the value of var1 in 'num1'.
				if var1 is not number, print "error\n" and go back to the beginning of the loop.*/
				if (var1[0] == '-')
				{
					for (j = 1; j < strlen(var1); j++)
					{
						if (var1[j] < '0' || var1[j] > '9')
							break;
					}
					if (j == strlen(var1))
						num1 = atoi(var1);
					else 
					{
						printf("error\n");
						continue;
					}
				}
				else if ('0' < var1[0] && var1[0] < '9')
				{
					for (j = 1; j < strlen(var1); j++)
					{
						if (var1[j] < '0' || var1[j] > '9')
							break;
					}
					if (j == strlen(var1))
						num1 = atoi(var1);
					else
					{
						printf("error\n");
						continue;
					}
				}

				/*if var1[0] is not '-' and number, check if there is var1 in 'name'.
				if var1 is 'name[index]', store 'value[index]' in 'num1'.
				if there is not var1 in 'name', print "error\n" and go back to the beginning of the loop. */
				else
				{
					for (j = 0; j < i; j++)
					{
						if (strcmp(var1, name[j]) == 0)
						{
							num1 = value[j];
							break;
						}
					}
					if (i == j)
					{
						printf("error\n");
						continue;
					}
				}

				/* if var2[0] is '-' or number, check if var2 is number or not.
				if var2 is number, store the value of var2 in 'num2'.
				if var2 is not number, print "error\n" and go back to the beginning of the loop.*/
				if (var2[0] == '-')
				{
					for (j = 1; j < strlen(var2); j++)
					{
						if (var2[j] < '0' || var2[j] > '9')
							break;
					}
					if (j == strlen(var2))
						num2 = atoi(var2);
					else
					{
						printf("error\n");
						continue;
					}
				}
				else if ('0' < var2[0] && var2[0] < '9')
				{
					for (j = 1; j < strlen(var2); j++)
					{
						if (var2[j] < '0' || var2[j] > '9')
							break;
					}
					if (j == strlen(var2))
						num2 = atoi(var2);
					else
					{
						printf("error\n");
						continue;
					}
				}

				/*if var2[0] is not '-' and number, check if there is var2 in 'name'.
				if var2 is 'name[index]', store 'value[index]' in 'num2'.
				if there is not var2 in 'name', print "error\n" and go back to the beginning of the loop. */
				else
				{
					for (j = 0; j < i; j++)
					{
						if (strcmp(var2, name[j]) == 0)
						{
							num2 = value[j];
							break;
						}
					}
					if (i == j)
					{
						printf("error\n");
						continue;
					}
				}

				// if op is '+', print a value of num1 + num2.
				if (op == '+')
					printf("%d\n", num1 + num2);

				// if op is '-', print a value of num1 - num2.
				else if (op == '-')
					printf("%d\n", num1 - num2);

				// if op is '*', print a value of num1 * num2.
				else if (op == '*')
					printf("%d\n", num1 * num2);

				/* if op is '/', check if num2 is 0.
				if num2 is 0, print "error\n".
				if num2 us not 0, print a value of num1 / num2. */
				else if (op == '/')
				{
					if (num2 == 0)
						printf("error\n");
					else printf("%d\n", num1 / num2);
				}

				// if op is not '+', '-', '*', or '/', print "error\n".
				else printf("error\n");
			}
			else printf("error\n");
		}
	}

	// free all dynamic allocated arrays.
	free(line);
	for (i = 0; i < 32; i++)
		free(name[i]);
	free(name);
	free(com);
	free(value);
	free(var1);
	free(var2);

	return 0;
}