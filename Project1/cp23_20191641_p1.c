#include <stdio.h>
#include <stdlib.h>

typedef enum {
	korean = 0, japanese, chinese
}food_style;

typedef struct __Food {
	int number;
	char name[20];
	food_style style;
	int cooking_time;
}Food;

typedef struct __Order* nptr;

typedef struct __Order {
	Food *pfood;
	int waiting_time;
	nptr order_link;
	nptr style_link;
}Order;

nptr order_front = NULL;
nptr order_rear = NULL;
nptr style_front[3] = { NULL, };
nptr style_rear[3] = { NULL, };

void print_order() {
	printf("Order List\n");
	int i = 1;
	for (nptr cur = order_front; cur;cur = cur->order_link, i++)
		printf("#%2d %15s %2d %3d\n", i, cur->pfood->name, cur->pfood->cooking_time, cur->waiting_time);
}

void enqueue(Food* data)
{
	nptr neworder = (Order*)malloc(sizeof(Order));
	neworder->pfood = data;
	neworder->order_link = NULL;
	
	if (order_front == NULL)
		order_front = neworder;
	else
		order_rear->order_link = neworder;
	order_rear = neworder;
}

int main()
{
	FILE* menu = fopen("menu.txt", "r");

	Food** food;

	int norder, nfood, num;
	char style[9];

	fscanf(menu, "%d", &nfood);

	food = (Food**)malloc(nfood * sizeof(Food*));

	for (int i = 0; i < nfood; i++)
	{
		food[i] = (Food*)malloc(sizeof(Food));
		fscanf(menu, "%d %s %s %d", &food[i]->number, food[i]->name, style, &food[i]->cooking_time);
		if (strcmp(style, "korean") == 0)
			food[i]->style = 0;
		else if (strcmp(style, "japanese") == 0)
			food[i]->style = 1;
		else if (strcmp(style, "chinese") == 0)
			food[i]->style = 2;
	}

	scanf("%d", &norder);

	for (int i = 0; i < norder; i++)
	{
		scanf("%d", &num);
		enqueue(food[num]);
	}

	print_order();

	return 0;
}