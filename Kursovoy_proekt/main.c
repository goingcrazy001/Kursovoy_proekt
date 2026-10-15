#include <stdio.h>
#include <locale.h>
#include <math.h>

double Q(double X) {
	if (X < 2) {
		X = 5 * sqrt(X - 2 + 1);
	}
	else if (X >= 2 && X <= 7) {
		X = 2 * (X - 4.5) + 50;
	}
	else if (X > 7) {
		X = 4 * log(X - 7 + 2) + 60;
	}
	return X;
}
int F()
{
	setlocale(LC_ALL, "RUS");

	double X;
	printf("Введите X в диапазоне [0,21]:");
	scanf("%lf", &X);
	if (X>=0 && X<=21) {
		printf("Вывод Q(X): %.2lf", Q(X));
	}
	else {
		printf("Ошибка, введенное число лежит не в заданном диапазоне.");
	}
}
