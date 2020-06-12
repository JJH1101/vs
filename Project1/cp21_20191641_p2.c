#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char Data;
	struct _NODE *prev;
	struct _NODE *next;
}NODE;

NODE* head;
NODE* tail;

void PrintList()
{
	NODE *cur = head;
	while (1)
	{
		printf("%c", cur->Data);
		if (cur->next == NULL)
			break;
		cur = cur->next;
	}
	printf("\n");
}

void PrintListReverse()
{
	NODE *cur = tail;
	while (1)
	{
		printf("%c", cur->Data);
		if (cur->prev == NULL)
			break;
		cur = cur->prev;
	}
	printf("\n");
}

void main()
{
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	NODE* mid = (NODE*)malloc(sizeof(NODE));
	head->Data = 'a'; mid->Data = 'b'; tail->Data = 'c';
	head->prev = NULL; head->next = mid;
	mid->prev = head; mid->next = tail;
	tail->prev = mid; tail->next = NULL;
	PrintList();
	PrintListReverse();

	free(head);
	free(mid);
	free(tail);
}