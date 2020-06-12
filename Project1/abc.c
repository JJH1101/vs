#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[10];
	char mail[20];
	int mobile;
	char major[10];
	int id;
	float cgpa;
}person;

void printPerson(person ps)
{
	printf("-------------------------\n");
	if (ps.name[0] != NULL)
		printf("name: %s\n", ps.name);
	if (ps.mail[0] != NULL)
		printf("mail: %s\n", ps.mail);
	if (ps.mobile != -1)
		printf("mobile: %d\n", ps.mobile);
	if (ps.major[0] != NULL)
		printf("major: %s\n",ps.major);
	if (ps.id != -1)
		printf("id: %d\n",ps.id);
	if (ps.cgpa != -1)
		printf("cgpa: %f\n", ps.cgpa);
}

int main()
{
	person person1, person2;

	strcpy(person1.name, "james");
	strcpy(person1.mail, "james@hanmail.net");
	person1.mobile = 6055726;
	person1.major[0] = NULL;
	person1.id = -1;
	person1.cgpa = -1;

	strcpy(person2.name, "david");
	strcpy(person2.major, "cs");
	person2.id = 20010123;
	person2.cgpa = 0.55;
	person2.mail[0] = NULL;
	person2.mobile = -1;

	printPerson(person1);
	printPerson(person2);

	return 0;
}