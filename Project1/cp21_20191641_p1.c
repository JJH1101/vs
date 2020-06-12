#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char data;
	struct _NODE *LINK;
}NODE;

NODE *head;

void InsertNode(char target, char a)
{
	NODE *newnode;
	newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = a;

	NODE* cur = head;

	if (cur->LINK == NULL)
	{
		newnode->LINK = NULL;
		cur->LINK = newnode;
		return;
	}

	while (1)
	{
		if (cur->LINK == NULL)
			break;
		else if (cur->LINK->data == target)
		{
			newnode->LINK = cur->LINK->LINK;
			cur->LINK->LINK = newnode;
			return;
		}
		cur = cur->LINK;
	}

	cur = head;

	while (1)
	{
		if (cur->LINK->LINK == NULL)
		{
			newnode->LINK = NULL;
			cur->LINK->LINK = newnode;
			break;
		}
		cur = cur->LINK;
	}
}

void DeleteNode(char target)
{
	NODE* cur = head;

	if (cur->LINK == NULL)
		return;

	NODE* temp;
	for (; cur->LINK != NULL; cur = cur->LINK)
	{
		if (cur->LINK->data == target)
		{
			temp = cur->LINK;
			cur->LINK = cur->LINK->LINK;
			free(temp);
			return;
		}
	}

	cur = head;

	for (; cur->LINK != NULL; cur = cur->LINK)
	{
		if (cur->LINK->LINK == NULL)
		{
			temp = cur->LINK;
			cur->LINK = cur->LINK->LINK;
			free(temp);
			break;
		}
	}
}

void PrintList()
{
	NODE* cur = head;
	for (; cur->LINK != NULL; cur = cur->LINK)
		printf("%c", cur->LINK->data);
	printf("\n");
}

void freelist()
{
	NODE* cur = head;
	NODE* tmp;
	for (;cur != NULL;)
	{
		tmp = cur;
		cur = cur->LINK;
		free(tmp);
	}
}

void main()
{
	head = (NODE*)malloc(sizeof(NODE));
	head->LINK = NULL;

	InsertNode('a', 'c');
	InsertNode('a', 'm');
	InsertNode('c', 'o');
	InsertNode('a', 'p');
	InsertNode('a', 't');
	InsertNode('p', 'u');
	InsertNode('t', 'e');
	InsertNode('a', 'r');
	PrintList();
	DeleteNode('a');
	DeleteNode('c');
	DeleteNode('o');
	DeleteNode('p');
	PrintList();
	freelist();
}