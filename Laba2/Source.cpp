#include <locale>
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
	setlocale(0, "russian");
	float A, X;
	puts("¬ведите X:");
	scanf_s("%f", &X);
	printf("X=%5.2f\n", X);
	A = sqrt((abs(sin(8*X)) + 17)) / (1 - sin(4 * X) * cos(X * X + 18));
	printf("A= %5.3f\n", A);
	return 0;
}
