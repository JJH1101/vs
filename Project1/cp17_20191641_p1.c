#include <stdio.h>

typedef struct __Complex
{
	int r;
	int i;
} Complex;

Complex Add(Complex a, Complex b)
{
	Complex result;
	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return result;
}

Complex Sub(Complex a, Complex b)
{
	Complex result;
	result.r = a.r - b.r;
	result.i = a.i - b.i;
	return result;
}

Complex Mul(Complex a, Complex b)
{
	Complex result;
	result.r = a.r * b.r - a.i * b.i;
	result.i = a.i * b.r + a.r * b.i;
	return result;
}
int main()
{
	Complex a, b;
	scanf("%d %d %d %d", &a.r, &a.i, &b.r, &b.i);

	printf("%d %d\n", Add(a, b).r, Add(a, b).i);
	printf("%d %d\n", Sub(a, b).r, Sub(a, b).i);
	printf("%d %d\n", Mul(a, b).r, Mul(a, b).i);

	return 0;
}