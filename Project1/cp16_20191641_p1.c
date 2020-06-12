#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	struct
	{
		float mid;
		float fin;
		float proj;
	}Points;
	char name[40];
	int studentId;
	char grade[3];
	float total_score;
}Grades;

int main()
{
	FILE *in = fopen("input.txt", "r");

	int n;

	fscanf(in, "%d", &n);

	Grades* info;
	info = (Grades*)malloc(n * sizeof(Grades));

	for (int i = 0; i < n; i++)
		fscanf(in, "%d\n%s\n%f\n%f\n%f\n",&info[i].studentId,info[i].name,&info[i].Points.mid, &info[i].Points.fin, &info[i].Points.proj);

	for (int i = 0; i < n; i++)
		info[i].total_score = info[i].Points.mid * 0.3 + info[i].Points.fin * 0.3 + info[i].Points.proj * 0.4;

	Grades temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (info[j].total_score < info[j + 1].total_score)
			{
				temp = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (info[i].total_score < 50)
			info[i].grade[0] = 'F';
		else if (i < (n * 0.3))
			info[i].grade[0] = 'A';
		else if (i < (n * 0.7))
			info[i].grade[0] = 'B';
		else
			info[i].grade[0] = 'C';
	}

	printf("-- Student LIst --\n\n");

	for (int i = 0; i < n; i++)
	{
		printf("Id : %d\n", info[i].studentId);
		printf("Name : %s\n", info[i].name);
		printf("Score(mid) : %f\n", info[i].Points.mid);
		printf("Score(final) : %f\n", info[i].Points.fin);
		printf("Score(project) : %f\n", info[i].Points.proj);
		printf("Grade : %c (%.2f, %d)\n", info[i].grade[0], info[i].total_score, i + 1);
		printf("\n");
	}

	free(info);
	fclose(in);
	return 0;
}