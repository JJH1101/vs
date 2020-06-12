#include <stdio.h>
#include <math.h>

void get_distance(double *pa, double *pb, double *pc, double *pd)
{
	*pa = sqrt((*pa - *pc) * (*pa - *pc) + (*pb - *pd) * (*pb - *pd));
}
int main()
{
	double a, b, c, d;
	printf("Input a, b, c, d : ");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	get_distance(&a, &b, &c, &d);
	printf("%.4lf\n", a);
	return 0;
}