#include <stdio.h>
#include <string.h>

typedef struct __Person
{
	char name[50];
	char email[50];
	int valid;
} Person;

void CheckEmailName(Person *a)
{
	for (int i = 0; i < strlen(a->name); i++)
	{
		if ('A' > a->name[i] || 'z' < a->name[i])
		{
			a->valid = 0;
			return;
		}
		else if ('Z' < a->name[i] && 'a' > a->name[i])
		{
			a->valid = 0;
			return;
		}
	}

	int at = 0, dot = 0;
	for (int i = 0; i < strlen(a->email); i++)
	{
		if (a->email[i] == '@') 
			at = i;
		else if (a->email[i] == '.') 
			dot = i;
	}

	if (at == 0 || dot == 0 || dot < at || dot == at + 1 || at == strlen(a->email) - 1 || dot == strlen(a->email) - 1)
	{
		a->valid = 0;
		return;
	}

	for (int i = 0; i < strlen(a->email); i++)
	{
		if (i != at && i != dot)
		{
			if ('A' > a->email[i] || 'z' < a->email[i])
			{
				a->valid = 0;
				return;
			}
			else if ('Z' < a->email[i] && 'a' > a->email[i])
			{
				a->valid = 0;
				return;
			}
		}
	}

	a->valid = 1;
	return;
}

int main()
{
	FILE* in;
	in = fopen("input.txt", "r");
	Person info[10];
	int n;

	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(in, "%s\n%s\n", info[i].name, info[i].email);

	for (int i = 0; i < n; i++)
		CheckEmailName(&info[i]);

	for (int i = 0; i < n; i++)
	{
		if (info[i].valid == 1)
		{
			printf("%s\t%s\n", info[i].name, info[i].email);
		}
	}

	fclose(in);
	return 0;
}