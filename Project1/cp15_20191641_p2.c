#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	double water;
} waterContainer;

void addWater(waterContainer* cup, double water)
{
	cup->water += water;
}

void combineWater(waterContainer* cup1, waterContainer* cup2)
{
	cup1->water += cup2->water;
	cup2->water = 0;
}

void removeWater(waterContainer* cup)
{
	cup->water = 0;
}

int main()
{
	waterContainer *cup1, *cup2;
	cup1 = (waterContainer*)malloc(sizeof(waterContainer));
	cup2 = (waterContainer*)malloc(sizeof(waterContainer));
	cup1->water = 0;
	cup2->water = 0;

	int operationNum, cup;
	double water;

	for (;;)
	{
		printf("choose operation.\n0: quit, 1: addWater, 2: removeWater, 3: combineWater\n");
		scanf("%d", &operationNum);

		if (operationNum == 0)
		{
			printf("cup1: %.2lf, cup2: %.2lf\n", cup1->water, cup2->water);
			break;
		}

		else if (operationNum == 1)
		{
			printf("choose cup : ");
			scanf("%d", &cup);
			printf("input water: ");
			scanf("%lf", &water);
			if (cup == 1)
				addWater(cup1, water);
			else if (cup == 2)
				addWater(cup2, water);
		}

		else if (operationNum == 2)
		{
			printf("choose cup : ");
			scanf("%d", &cup);
			if (cup == 1)
				removeWater(cup1);
			else if (cup == 2)
				removeWater(cup2);
		}

		else if (operationNum == 3)
			combineWater(cup1, cup2);
	}

	free(cup1);
	free(cup2);

	return 0;
}