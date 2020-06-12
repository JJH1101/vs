#include <stdio.h>

int find_value(int *start, int *end, int target)
{
	for (; start <= end; start++)
	{
		if (*start == target) return 1;
	}
	return 0;
}

int main()
{
	int n;
	int ary[1000];
	int start, end, target;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ary[i]);
	}
	scanf("%d %d %d", &start, &end, &target);
	if (find_value(&ary[start], &ary[end], target))
		printf("True\n");
	else
		printf("False\n");
}