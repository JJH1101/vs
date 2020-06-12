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


int main()
{
	NODE *head;
	head = NULL;
	
	int *num = (int*)malloc(6 * sizeof(int));
	int i;

	for (i = 0; i < 6; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] == -1) break;
	}

	if (i == 1)
	{
		NODE *node1 = (NODE*)malloc(sizeof(NODE));
		node1->data = num[0];
		node1->link = NULL;
		head = node1;
		Print(head);
		free(node1);
	}
	else if(i == 2)
	{
		NODE *node1 = (NODE*)malloc(sizeof(NODE));
		NODE *node2 = (NODE*)malloc(sizeof(NODE));
		node1->data = num[0];
		node1->link = node2;
		head = node1;
		node2->data = num[1];
		node2->link = NULL;
		Print(head);
		free(node1);
		free(node2);
	}
	else if (i == 3)
	{
		NODE *node1 = (NODE*)malloc(sizeof(NODE));
		NODE *node2 = (NODE*)malloc(sizeof(NODE));
		NODE *node3 = (NODE*)malloc(sizeof(NODE));
		node1->data = num[0];
		node1->link = node2;
		head = node1;
		node2->data = num[1];
		node2->link = node3;
		node3->data = num[2];
		node3->link = NULL;
		Print(head);
		free(node1);
		free(node2);
		free(node3);
	}
	else if (i == 4)
	{
		NODE *node1 = (NODE*)malloc(sizeof(NODE));
		NODE *node2 = (NODE*)malloc(sizeof(NODE));
		NODE *node3 = (NODE*)malloc(sizeof(NODE));
		NODE *node4 = (NODE*)malloc(sizeof(NODE));
		node1->data = num[0];
		node1->link = node2;
		head = node1;
		node2->data = num[1];
		node2->link = node3;
		node3->data = num[2];
		node3->link = node4;
		node4->data = num[3];
		node4->link = NULL;
		Print(head);
		free(node1);
		free(node2);
		free(node3);
		free(node4);
	}
	else if (i == 5)
	{
		NODE *node1 = (NODE*)malloc(sizeof(NODE));
		NODE *node2 = (NODE*)malloc(sizeof(NODE));
		NODE *node3 = (NODE*)malloc(sizeof(NODE));
		NODE *node4 = (NODE*)malloc(sizeof(NODE));
		NODE *node5 = (NODE*)malloc(sizeof(NODE));
		node1->data = num[0];
		node1->link = node2;
		head = node1;
		node2->data = num[1];
		node2->link = node3;
		node3->data = num[2];
		node3->link = node4;
		node4->data = num[3];
		node4->link = node5;
		node5->data = num[4];
		node5->link = NULL;
		Print(head);
		free(node1);
		free(node2);
		free(node3);
		free(node4);
		free(node5);
	}
	
	return 0;
}