#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
	int value;
	struct __node *next;
}NODE;

NODE* head;
NODE* tail;

void initHeadTail()
{
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	head->value = -1;
	head->next = tail;
	tail->value = -1;
	tail->next = NULL;
}
	
void insertNode(int data)
{
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->value = data;
	new->next = tail;

	NODE* cur = head;
	while (1)
	{
		if (cur->next->next == NULL)
		{
			cur->next = new;
			break;
		}
		cur = cur->next;
	}
}

void printNode()
{
	NODE* cur = head->next;
	for (; cur->next != NULL; cur = cur->next)
		printf("%d ", cur->value);
	printf("\n");
}

void freeNode()
{
	NODE* cur = head;
	NODE* temp;
	for (; cur != NULL; )
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
}

int main()
{
	initHeadTail();

	int n;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		insertNode(n);
	}
	
	printNode();

	freeNode();
	return 0;
}