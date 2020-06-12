#include <stdio.h>

void Sort(int* num1, int* num2, int* num3)
{
	int temp;
	int num[] = { *num1,*num2,*num3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2 - i; j++)
		{
			if (num[j] < num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	*num1 = num[0];
	*num2 = num[1];
	*num3 = num[2];
}

int main()
{
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);
	Sort(&num1, &num2, &num3);
	printf("%d %d %d\n", num1, num2, num3);
	return 0;
}