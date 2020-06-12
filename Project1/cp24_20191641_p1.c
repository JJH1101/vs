#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CNT 5

typedef struct __NODE* NODE_P;
typedef struct __NODE {
	char command[10];
	NODE_P next;
}NODE;

typedef struct {
	int count;
	NODE_P front;
	NODE_P rear;
}queue;

queue* command_list;

void init_queue()
{
	command_list = (queue*)malloc(sizeof(queue));
	command_list->count = 0;
	command_list->front = NULL;
	command_list->rear = NULL;
}

void print_queue()
{
	if (command_list->front == NULL)
	{
		printf("NO HISTORY!\n");
		return;
	}

	int i = 1;
	NODE_P cur = command_list->front;
	while (1)
	{
		if (cur == NULL)
			break;
		printf("%d : %s\n", i, cur->command);
		cur = cur->next;
		i++;
	}
}

void enqueue(char* command)
{
	NODE_P newnode = (NODE_P)malloc(sizeof(NODE));
	strcpy(newnode->command, command);
	newnode->next = NULL;

	if (command_list->front == NULL)
		command_list->front = newnode;
	else
	{
		command_list->rear->next = newnode;
	}
	command_list->rear = newnode;
	(command_list->count)++;
}

void dequeue()
{
	NODE_P temp;

	if (command_list->count == 0)
		return;
	else if (command_list->count == 1)
	{
		temp = command_list->front;
		command_list->front = NULL;
		command_list->rear = NULL;
		free(temp);
		(command_list->count)--;
	}
	else
	{
		temp = command_list->front;
		command_list->front = command_list->front->next;
		free(temp);
		(command_list->count)--;
	}
}

int main() {
	init_queue();

	char com[10];

	while (1)
	{
		printf(">>");
		scanf("%s", com);
		if (strcmp(com, "history") == 0)
			print_queue();
		else if (strcmp(com, "quit") == 0)
			break;
		enqueue(com);
		if (command_list->count > 5)
			dequeue();
	}

	NODE_P temp;

	while (1)
	{
		if (command_list->front == NULL)
			break;
		temp = command_list->front;
		command_list->front = command_list->front->next;
		free(temp);
	}

	free(command_list);

	return 0;
}
