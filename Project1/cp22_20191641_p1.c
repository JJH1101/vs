#include <stdio.h>
#include <stdlib.h>

int st[20];
int top = -1;

void stack_push(int data)
{
	top++;
	st[top] = data;
}

int stack_pop()
{
	int data = -1;

	if (top == -1)
		printf("stack is empty!\n");
	else
	{
		data = st[top];
		top--;
		printf("removed data : %d\n", data);
	}

	return data;
}

void stack_print()
{
	if (top == -1)
		printf("stack is empty!\n");
	else if (top >= 20)
		printf("stack is full!\n");
	else
	{
		printf("stack_print : ");
		for (int i = top; i >= 0; i--)
			printf("%d ", st[i]);
		printf("\n");
	}
}

int main()
{
	int option = 0, num;
	printf("<option>\n(push : 1 data) | (pop : 2) | (stack print : 3)\n");
	while (1)
	{
		scanf("%d", &option);
		if (option == -1)
			break;
		switch (option)
		{
		case 1:
			scanf("%d", &num);
			stack_push(num);
			break;
		case 2:
			stack_pop();
			break;
		case 3:
			stack_print();
			break;
		default:
			printf("Wrong option!\n");
		}
	}
	return 0;
}