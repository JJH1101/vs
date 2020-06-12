#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
	int value_tongue;
	int value_elbow;
	struct __node* next_tongue;
	struct __node* next_elbow;
} NODE;

NODE* head_tongue;
NODE* tail_tongue;

NODE* head_elbow;
NODE* tail_elbow;

void initHeadTail()
{
	head_tongue = (NODE*)malloc(sizeof(NODE));
	tail_tongue = (NODE*)malloc(sizeof(NODE));
	head_elbow = (NODE*)malloc(sizeof(NODE));
	tail_elbow = (NODE*)malloc(sizeof(NODE));

	head_tongue->value_tongue = -1;
	head_tongue->next_tongue = tail_tongue;
	tail_tongue->value_tongue = -1;
	tail_tongue->next_tongue = NULL;

	head_elbow->value_elbow = -1;
	head_elbow->next_elbow = tail_elbow;
	tail_elbow->value_elbow = -1;
	tail_elbow->next_elbow = NULL;
}

void insertNode(int t, int e)
{
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->value_tongue = t;
	new->value_elbow = e;

	NODE* cur_tongue = head_tongue;
	NODE* cur_elbow = head_elbow;

	while (1)
	{
		if (new->value_tongue <= cur_tongue->next_tongue->value_tongue)
		{
			new->next_tongue = cur_tongue->next_tongue;
			cur_tongue->next_tongue = new;
			break;
		}
		else if (cur_tongue->next_tongue->value_tongue == -1)
		{
			new->next_tongue = cur_tongue->next_tongue;
			cur_tongue->next_tongue = new;
			break;
		}
		cur_tongue = cur_tongue->next_tongue;
	}

	while (1)
	{
		if (new->value_elbow <= cur_elbow->next_elbow->value_elbow)
		{
			new->next_elbow = cur_elbow->next_elbow;
			cur_elbow->next_elbow = new;
			break;
		}
		else if (cur_elbow->next_elbow->value_elbow == -1)
		{
			new->next_elbow = cur_elbow->next_elbow;
			cur_elbow->next_elbow = new;
			break;
		}
		cur_elbow = cur_elbow->next_elbow;
	}
}

void printTongue()
{
	NODE* cur;
	cur = head_tongue;

	printf("Tongue list : ");
	for (; cur->next_tongue->next_tongue != NULL; cur = cur->next_tongue)
		printf("%d ", cur->next_tongue->value_tongue);
	printf("\n");
}

void printElbow()
{
	NODE* cur;
	cur= head_elbow;

	printf("Elbow list : ");
	for (; cur->next_elbow->next_elbow != NULL; cur = cur->next_elbow)
		printf("%d ", cur->next_elbow->value_elbow);
	printf("\n");
}

void freeNode()
{
	NODE* cur_tongue = head_tongue;
	NODE* cur_elbow = head_elbow;

	while (cur_tongue != NULL)
	{
		free(cur_tongue);
		free(cur_elbow);

		cur_tongue = cur_tongue->next_tongue;
		cur_elbow = cur_elbow->next_elbow;
	}
}

int main()
{
	initHeadTail();

	int t, e;

	for (int i = 0; i < 5; i++)
	{
		printf("input a tongue and elbow node!\n");
		printf("input a tongue length : ");
		scanf("%d", &t);
		printf("input a elbow length : ");
		scanf("%d", &e);
		printf("\n");

		insertNode(t, e);
	}

	printTongue();
	printElbow();

	freeNode();
	return 0;
}