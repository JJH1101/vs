#include <stdio.h>

int main()
{
	int n;
	int ary[1000];
	while (1)
	{
		scanf("%d", &n);
		if (n % 4 == 0) break;
	}
	for (int i = 0; i < n; i++)
	{
		ary[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
		if ((i + 1) % 4 == 0) printf("\n");
	}
	return 0;
}