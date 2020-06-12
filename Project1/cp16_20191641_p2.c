#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct
	{
		struct
		{
			char Hall[3];
			int floor;
		}Where;

		struct
		{
			char menu[10];
			int num;
		}What;

	}order;

	printf("Where? (hall, floor) : ");
	scanf("%s %d", order.Where.Hall, &order.Where.floor);
	printf("What? (menu, #) : ");
	scanf("%s %d", order.What.menu, &order.What.num);

	printf("_________________________\n");
	printf("|                       |\n");
	printf("|\tI want pizza\t|\n");
	printf("|\t%d %-10s\t|\n", order.What.num, order.What.menu);
	printf("|                       |\n");
	printf("|\tBring me on\t|\n");
	printf("|\t%dF, Hall %-3s\t|\n", order.Where.floor, order.Where.Hall);
	printf("|                       |\n");
	printf("-------------------------\n");

	return 0;
}