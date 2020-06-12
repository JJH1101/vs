#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	int data;
	struct _NODE *link;
}NODE;

void Print(NODE* head)
{
	NODE* step = head;
	for (;step->link != NULL; step = step->link)
		printf("%d ", step->data);
	printf("%d\n", step->data);
}

void sort(NODE* head)
{
	NODE* step = head;
	int n;
	for (int i = 0; i < 2; i++)
	{
		step = head;
		for (;step->link != NULL; step = step->link)
		{
			n = 0;
			if (step->data > step->link->data)
			{
				n = step->data;
				step->data = step->link->data;
				step->link->data = n;
			}
		}
	}
}

int main()
{
	NODE* head = NULL;
	NODE* node1 = (NODE*)malloc(sizeof(NODE));
	NODE* node2 = (NODE*)malloc(sizeof(NODE));
	NODE* node3 = (NODE*)malloc(sizeof(NODE));

	scanf("%d %d %d", &node1->data, &node2->data, &node3->data);
	
	head = node1;
	node1->link = node2;
	node2->link = node3;
	node3->link = NULL;

	sort(head);
	Print(head);

	return 0;
}