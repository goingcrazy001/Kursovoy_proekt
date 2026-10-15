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
<img width="730" height="846" alt="image" src="https://github.com/user-attachments/assets/2c8d3e39-6409-4f6d-bdf7-170bf643957d" />

[Ссылка на блок-схему](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22KYdzvYGNv-uggLIezpfg%22%3E7VttT%2BM4EP41leAkqsTO60cohTvpdsUeJx2737yNaXM4cXFd2u6vPztxmjhpIU0TKNeCCPF4PGlmnnnJxO3BQbS8ZWg6%2BUIDTHrACJY9eN0DwLR8KP5Jyiql%2BIYijFkYKKaccB%2F%2BwopoKOo8DPBMY%2BSUEh5OdeKIxjEecY2GGKMLne2REv2qUzTGFcL9CJEq9Z8w4JOU6gE3p%2F%2BOw%2FEku7Lp%2BOlMhDJmdSezCQrookCCwx4cMEp5ehYtB5hI5WV6SdfdbJldfzCGY15nweJHtBre3X6ZP4Ebevvj1%2FPX528XproPHFTUkMtVpBmdsxF%2BTZji46tMe1LsvRpSxid0TGNEhjn1itF5HGD5EQ0xynn%2BpHQqiKYg%2Fos5XylkoDmngjThEVGzjzTmNygKiQTY32EkwAKMr3ghjn%2FRCMWKRa03bTUeUEKZIBBpu4sAsaezHoBG8tMDg%2FX5ueBXsENsjPkrt2%2BlfC%2BIzNXtr60s3APTCHO2EgwME8TDF13fSOF0vObLTSlOlDV3sex2OxbsQ4hwJGmHxSTk%2BH6KEgMvhC%2FrWhbgneI%2F4plwxkzvISGblRgg7D2OEiUKVcJHIH%2BlHmec0SecLRJTzsjDPx8bWKSB0TcYxyFcfqqp4C9qxXmeS5%2B80s7GyX8BUv9aHq%2BMntCC52bn4pjMXg0zscJoqWS1NL08ZhwvC9aoomNSiCaeCh2LPPKYtqIpKRCqeLPS42breAInPL2BJwmOSwUCeUyBYidAcbqyvw8Nzf4e6AoAptNiqrCOO1XYB5UqrDqunXisOBVciBBM6JihSNzxFDOhSY5Zee4un2gSDZY4qwbN93HoBgGoYsWHRm7ubHBztxTmQSnMw87c3GvRze3jdnOnApCPdHO7jpvr2n%2FDbz%2BJV35rzyudklc6mlcCqzOv9Fv0Sue4vdI7KK%2FM6rWTZfe3rL%2BPZZVPG33Ds%2BB2YyfSLhlDqwLDlIYxnxUudicJuVAH2FqggL5RAk4qMYfR%2BtM2R5ZTK95PaPRzPmtUo32O6C9qMgdF8m6S53JhoptG%2BWDTwxgsVWmWXqVBu6t84B1rLs%2FaK0H4srFpI695MUsueikYTLMP7OmWbs7uDaCHrd0dI1lpCDc3fpPCnhk%2Fa%2FcCF%2BIPJPqRI%2FO8wJkoY48%2BU4NSx%2FI6azSZLSZE%2FyMSIl6G%2FEEu79tq9L0wc71UkpPBKhvEQneFRXL4vTiXL0tG2brDSb6m2XZdtTmX2p6rIdHOOqCZiBQUalXxhUg5KUNdkANKgtJbrghqKz8D8NmBfkDgA%2B2UfhUM7F36eZZe%2Bln2O5R%2B%2Fqn0U6Wfsa7%2B0vSYZGlQpKfHytDQFpN8sdu0gDSNtytIO0vFGVqMzjoKtV4QnkrIWiVkTVF%2B333PYhSoYrSDQtTq2%2BfrWlRGtM216HtWqHYpndudPXwB2GLizjLX0WZu2HbZuF9YBKfUKe%2FwbEPuFLnvvJH31miduF4p8bmdJT54Snz%2F88RnqcRH6LiD3OeuEx%2FIc6BzEDnQtUuPtJ2Vj8BqMwce%2BXvivR5e2w%2BQtV4Un%2FaDfOR%2BEB%2Fo6dLtbt%2Bf3aKje1U%2Fj4NLuU1bjEYEzWbhSIeC7uV5l7RX7JHmLdMtXdImHdnDCQ9m3e1iRRBlTz8bY0YBWaX9hEbfMGHbrz8ts4RW65UeWLWDVlrtlbFet%2BHrlZorrlMS1HXDt80dlGY1JO%2FoS4fsE51CfYd3De5m4O7%2BrqG0AaAiqGvotfo9D3iCXufQc8sZvhysakc9qyvoiWH%2B9aWUPf8SGBz%2BBw%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)
Программа написана на языке C++
```c++
#include <stdio.h>
#include <locale.h>
#include <math.h>

main() {
	F()
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
