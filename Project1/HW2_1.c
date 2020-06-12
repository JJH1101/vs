#include <stdio.h>
#include <string.h>

int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	int up = 0, low = 0, arab = 0, blank = 0;

	char line[10000];

	for (;;)
	{
		if(fgets(line, 10000, in) == NULL) break;

		for (int i = 0; i < strlen(line); i++)
		{
			if ('a' <= line[i] && line[i] <= 'z')
				low++;
			else if ('A' <= line[i] && line[i] <= 'Z')
				up++;
			else if ('0' <= line[i] && line[i] <= '9')
				arab++;
			else if (line[i] == ' ' || line[i] == '\t')
				blank++;
		}
	}

	fprintf(out, "Number of upper case letters : %d\n", up);
	fprintf(out, "Number of lower case letters : %d\n", low);
	fprintf(out, "Number of arabic characters : %d\n", arab);
	fprintf(out, "Number of blanks : %d", blank);

	fclose(in);
	fclose(out);
	return 0;
}