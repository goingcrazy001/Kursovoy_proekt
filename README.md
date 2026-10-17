# Мониторинг реактора: концентрация O₂
## Постановка задач
Датчик технологической установки работает непрерывно и формирует последовательность показаний кислорода (O₂) в реакторе:
- `X(1), X(2),...,X(n)`.

Для оценки текущего состояния технологического процесса каждое измерение `X(i)` преобразуется в индикатор `Q(i)` помощью индивидуальной кусочной функции `F`:
- `Q(i)=F(X(i))`.

Функция преобразования `F(X)` задается следующим образом:
- `X<2: Q(i)=5*sqrt(X-2+1)+5`.
- `2<=X<=7: Q(i)=2*(X-4.5)+50`.
- `X>7: Q(i)=4*log(X-7+2)+60`.

В процессе поступления новых показаний `Q(i)` осуществляется оперативный контроль:
`X(i)→Q(i)→Control(Q(i))`.
- Устанавливается базовое значение индикатора `Q₀=50.00`.
- Проводится анализ отклонения текущего значения `Q(i)` от базового `Q₀`.
- Сигнализация о нарушении технологического режима инициируется при выполнении условия `|Q(i)-Q₀|>0.03*Q₀`.
- Наименования состояний технологического процесса определяются исполнителем.

Формируется массив показаний `Q[]` объемом `N=40` элементов. Для целей статистического анализа рассматривается подмассив `Q[1..14]`. Необходимо выполнить расчет следующих статистических показателей для данного подмассива:
- Среднее арифметическое значение.
- Cреднеквадратическое отклонение.

Для подтверждения корректности реализации алгоритма преобразования показаний (пункт 1) выполняется проверка на основе контрольного примера:
При входном значении `X=3.25`, ожидаемое значение индикатора `Q` должно составлять `47.50`.
## Задание 1
## Алгоритм и блок-схема
### Алгоритм
1. Начало
2. Функция Q(X) для вычисления значения индикатора, которая принимает число `X`:
- Если `X<2`, то возвращает значение, вычисленное по формуле : `5*sqrt(X-2+1)+5`.
- Если `2<=X<=7`, то возвращает значение, вычисленное по формуле : `2*(X-4.5)+50`.
- Если `X>7`, то возвращает значение, вычисленное по формуле : `4*log(X-7+2)+60`.

3. Главная программа F:
- Объявление переменной `X` типа `double`.
- Просит пользователя ввести число `X` в диапазоне `[0,21]`.
- Cчитывание введенного значения.
- Проверка, входит ли введенное число в допустимый диапазон:
  - Если да: то программа вызывает функцию `Q(X)` и выводит результат на экран.
  - Если нет: то программа выводит сообщение об ошибке.
4. Конец

### Блок-схема
<img width="739" height="849" alt="image" src="https://github.com/user-attachments/assets/64951e7e-a369-4bbd-a9ce-5bd75d17e660" />

[Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22KYdzvYGNv-uggLIezpfg%22%3E7Vttc5s4EP41nmluxh4Qr%2F6YOG831%2FbSpjeX5ptiZJtGWA6WYzu%2FvhJIBgFJMIaE1E4mBK1egN1nV89K0DEGweoihLPJF%2BIh3AGat%2BoYpx0AdM3Q2D8uWccSGxixYBz6nmiUCK79JyR7CunC99BcaUgJwdSfqcIhmU7RkCoyGIZkqTYbEaxedQbHKCe4HkKcl%2F7ve3QSS13gJPJL5I8n8sq63Y9rAigbiyeZT6BHlimRcdYxBiEhND4LVgOEufKkXuJ%2B58%2FUbm4sRFNapsPyNlifXV18WdyDc3Jx%2B%2FTw9eFbVxfPgbycGpJxhWhOFuEQvTSYaEfXUnt82GtRJCGdkDGZQnyWSE9Csph6iN%2BixkpJm8%2BEzJhQZ8JfiNK1QAZcUMJEExpgUTsiU3oOAx9zgP3wAwYWoH1FS3b8TgI4FU1Ef90S5QHBJGQCzG3X9WB4%2F6kDDC366YDB5vyItRewg%2BEY0Rce34zbPUK8EI%2B%2FsTJzD0QCRMM1axAiDKn%2FqOobCpyON%2B0SU7ITYc1tLPu8HVP2wZg5ErfDcuJTdD2DkYGXzJdVLTPwztDf0zlzRql3H%2BNiJXoQuaNhpESmSmME%2BC%2FX45yG5B7JTqzKHrroblTBIhWMXmAcG1N%2BVzPWPq0V%2B2HBffJEORtH%2FxlI%2B6f8eKJ1mBZcR56zY1R7ciaHZUaLRxZd48ujkKJVyhp5dExS0cQVoWOZRB7dEjIximGIeLNW42bteAIHPL2CJw6OYwECfoyBYkVAsZuyf19OsGs5MzUFAN2ucaow93uqsFo1VZhlXDvyWHbKWkGMESbjEAbsiWcoZJqkKMzWXSUVVaLBCkk2qL%2BNQ1cIQDkr3lRyc7vAzZ1MmAeZMG805uZujW5u7beb2zmAvKebW2XcXNX%2BK377QbzyW31eaWe80la8EpiNeWW%2FRq%2B099sr3ffyyn8Gv378d3n978PlrXmvA418N1FXXb%2BAd9IkWt6%2BLyIjY83P8A5h1QKQ6ZCp%2BXTIBoxmZe4Q%2FhDiY1ER%2BJ4XGxvN%2FSdxK9zcM%2BJPafTg1knHOn2W%2FZoiHSrrboUaFl26Wk9zbUfxL5mEFBlBjH7FbzXVhIxGc4aGrJU2N7FDQqQdXLIul%2Bzv4pICMBwvpvEKQI7DEK5TDQSy8%2FgRg9rAUhBo9LUMluIRqyKrMCSYO4aEzYpjC0JCOgkGdQUG4NgZOtyiuGCXolkTEtwt5pVSo49BulgqZMOAP020HMYMcV6JhhWtgRiZ5MhU0WBYTdEwd18ptFzV9PzHTtFaKb9mdx5d9Jg10PUesGbPLKJuv%2B568%2Byiqhb11FiQ1v7igz2E9FO9F%2BiyPxDph5f0o1TLSBk7LO9WyDDMfmPru3qNdKaYkzZMZ9DKpze8e88SpZ%2BpmtOVGDkqrGVhynSX6sSLP9N1SbeoJPu1hzrpet3pTDETslyVi1ty40EOEYNC9ErAmKdUhjqQDTIDxY%2BcG6gudgV2ZVfF25x%2FQsLF4otimm6beBUAHz1AtShogDyeqiRcOd%2FdOeFyTTXhMq03SLisXUMCaE9IaCThMjU5zUiztCgw9EuR8n1IuLRNzhWT0ogbg7Q8PuaKmtIZJ52dqmmbrr2et1mSAEtQaU2RW%2F2FqeKQuG2ZuJUcqt9z3jIFBCIFbCD9M3vW0SYD5PNRcQb4lnmhlSHRVmNLHvJ9zXreECyeKPeHdxm78K7a956MXXmP0R7eU3MqpGttojjSbw4cJ8dxduAoJZaWHTdDUZzGKIpxoCh%2FOEUxBUXBZNwAS3E2FAUkbMVuBVtxrMySX2NEXyam9bCVPX99badFovoDZKn31w6vqb7na6p9oE6XTnOfI1g1Orqb9%2FOpd8y%2FHuOUFcP53B%2BqUFC9PNlF6qT3kJItpWd2karsWLUnPOhl32JPg0jmqYUxI4WszGcOWk%2FTjbpf7jH1DFrNF9aa8yvVmd5uFutlN8TczDKYY2cGqm9DrNiV6vywQ8%2BH5C19qc0%2B0SjUt9iLdYqBu%2F1ebOb1ttxATUOv1s9PC1YjDtCrGXpOdobPBqvSUc9sCnqsmHxVHTdPvk03zn4D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)
## Реализация программы
Программа написана на языке C++
```c++
#include <stdio.h>
#include <locale.h>
#include <math.h>

main() {
	F();
}
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
```
## Результат работы программы
```
Введите X в диапазоне [0,21]:3,25
Вывод Q(X): 47,50
```
## Информация о разработчике
```
Имя: Харитонов Дмитрий Олегович
Группа: бИЦТ-261
Вариант: 32
```
