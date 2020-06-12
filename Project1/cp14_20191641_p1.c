#include <stdio.h>
#include <string.h>

typedef struct
{
	char student_name[10];
	char course_name[20];
}student;

typedef struct
{
	char course_name[20];
	double running_time;
}course;

int main()
{
	student st[10];
	course cor[10];
	FILE *s = fopen("student.txt", "r");
	FILE *c = fopen("course.txt", "r");
	int nums, numc;
	fscanf(s, "%d\n", &nums);
	for (int i = 0; i < nums; i++)
		fscanf(s, "%s %s\n",st[i].student_name,st[i].course_name);
	fscanf(c, "%d\n", &numc);
	for (int i = 0; i < numc; i++)
		fscanf(c, "%s %lf\n", cor[i].course_name, &cor[i].running_time);
	for (int i = 0; i < nums; i++)
	{
		for (int j = 0; j < numc; j++)
		{
			if (strcmp(st[i].course_name, cor[j].course_name) == 0)
			{
				printf("%s %.1lf\n", st[i].student_name, cor[j].running_time);
				break;
			}
		}
	}
	fclose(s);
	fclose(c);
	return 0;
}