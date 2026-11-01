#include <stdio.h>
#include <locale.h>
#include <math.h>
#define a 2.0
#define b 5.0
#define c 1.0
#define d 7.0
#define e 4.0
#define f 4.5
#define g 50.0
#define h 60.0
#define low_limit 1.0
#define high_limit 21.0

void welcome();
double calc_q(double X);
void result();

int main(void) {
	setlocale(LC_ALL, "RUS");
	welcome();
	result();
	return 0;
}

void welcome()
{
	printf("\n");
	printf("====================================================\n");
	printf("   Мониторинг реактора: концентрация кислорода (O2)\n");
	printf("----------------------------------------------------\n");
	printf("  Система преобразования показаний реактора\n");
	printf("  Математическая модель: Q = f(X)\n");
	printf("----------------------------------------------------\n");
	printf("  Допустимый диапазон X: %.0f - %.0f %%\n", low_limit, high_limit);
	printf("----------------------------------------------------\n");
	printf("  Введите концентрацию кислорода X (%%): ");
}
double calc_q(double X) {
	if (X < a) {
		X = b * sqrt(X - a + c);
	}
	else if (X >= a && X <= d) {
		X = a * (X - f) + g;
	}
	else if (X > d) {
		X = e * log(X - d + a) + h;
	}
	return X;
}


void result()
{
	double X;
	scanf("%lf", &X);
	if (X>=low_limit && X<=high_limit) {
		printf("\n  Результат Q(X): %.2lf", calc_q(X));
	}
	else {
		printf("\n  Ошибка, введенное число лежит не в заданном диапазоне!");
	}
}