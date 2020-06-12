#include <stdio.h>
#include <stdlib.h>

typedef struct __NODE {
	int data;
	struct __NODE* link;
}NODE;

typedef struct {
	int cnt;
	NODE* top;
}STACK;

STACK* st = NULL;

int stack_push(int data) 
{
	NODE* newnode = (NODE*)malloc(sizeof(NODE));

	if (newnode == NULL)
		return 0;
	else
	{
		newnode->data = data;
		newnode->link = st->top;
		st->top = newnode;
		st->cnt++;
		return 1;
	}
}

int stack_pop() 
{
	int data = -1;

	if (st->top == NULL)
		printf("stack is empty!\n");

	else
	{
		NODE* temp;
		temp = st->top;
		data = (st->top)->data;
		st->top = (st->top)->link;
		st->cnt--;
		free(temp);

		printf("removed data : %d\n", data);
	}

	return data;
}

void stack_print() 
{
	if (st->top == NULL)
		printf("stack is empty!\n");

	else
	{
		NODE* cur = st->top;
		printf("stack print : ");
		while (1)
		{
			if (cur == NULL)
				break;
			else
			{
				printf("%d ", cur->data);
				cur = cur->link;
			}
		}
		printf("\n");
	}
}

void stack_init() 
{
	st = (STACK*)malloc(sizeof(STACK));
	st->top = NULL;
	st->cnt = 0;
}

void stack_free()
{
	NODE* cur = st->top;
	NODE* temp;

	while (1)
	{
		if (cur == NULL)
			break;
		else
		{
			temp = cur;
			cur = cur->link;
			free(temp);
		}
	}
}

int main() {
	int option = 0, num;
	stack_init();
	printf("<option>\n(push : 1 data) | (pop : 2) | (print stack : 3) \n");
	while (1) {
		scanf("%d", &option);
		if (option == -1)
			break;
		switch (option) {
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
		default: printf("Wrong option!\n");break;
		}
	}

	stack_free();
	return 0;
}
