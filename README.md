# Мониторинг реактора: концентрация O₂
> Курсовой проект по дисциплине «Основы программирования и алгоритмизации».  
## Постановка задач
Датчик технологической установки работает непрерывно и формирует последовательность показаний кислорода $(O_2)$ в реакторе:
- $X(1), X(2),...,X(n)$

Для оценки текущего состояния технологического процесса каждое измерение $X(i)$ преобразуется в индикатор $Q(i)$ помощью индивидуальной кусочной функции $F$:
- $Q(i)=F(X(i))$

В процессе поступления новых показаний $Q(i)$ осуществляется оперативный контроль:
$X(i)→Q(i)→Control(Q(i))$.
- Устанавливается базовое значение индикатора $Q_2=50.00$.
- Проводится анализ отклонения текущего значения $Q(i)$ от базового $Q_2$.
- Сигнализация о нарушении технологического режима инициируется при выполнении условия $|Q(i)-Q_2|>0.03*Q_2$.
- Наименования состояний технологического процесса определяются исполнителем.

Формируется массив показаний $Q[]$ объемом $N=40$ элементов. Для целей статистического анализа рассматривается подмассив $Q[1..14]$. Необходимо выполнить расчет следующих статистических показателей для данного подмассива:
- Среднее арифметическое значение.
- Cреднеквадратическое отклонение.

Для подтверждения корректности реализации алгоритма преобразования показаний выполняется проверка на основе контрольного примера:
При входном значении $X=3.25$, ожидаемое значение индикатора $Q$ должно составлять $47.50$.
## Описание входных данных
В качестве входного параметра используется концентрация кислорода в реакторе.
| Параметр | Значение |
|:-----|:-----------:|
| Название | Концентрация O₂ |
| Обозначение | X |
| Единица измерения | % |
| Диапазон датчика | 0-21 | 
| Количество измерений | 40 |

Для вычисления функции необходимо учитывать область её математической определённости. При значениях $X$ от $0$ до $1$ подкоренное выражение отрицательно, поэтому такие значения не могут использоваться для расчёта $Q$.

Таким образом, фактический допустимый диапазон $X$ для вычисления функции составляет $1–21$.
## Математическая модель
Преобразование показания выполняется по индивидуальной кусочной функции:

$$
Q(X) = \begin{cases}
5\cdot\sqrt{X-2+1}+5, &\text{при } 1 \le X < 2 \\
2\cdot(X-4.5)+50, &\text{при } 2 \leq X \leq 7 \\
4\cdot\ln(X-7+2)+60, &\text{при } X > 7
\end{cases}
$$
## Ручная проверка математической модели

Для проверки правильности заданной функции выполним расчёты для трёх значений X, принадлежащих разным участкам определения.

Пример 1: $X = 1.5$
Поскольку $1 ≤ 1.5 < 2$, используется первая ветвь:

$Q(1.5)=5\sqrt{1.5-1}+5$

$Q(1.5)=5\sqrt{0.5}+5$

$\boxed{Q(1.5)\approx8.54}$

Пример 2: $X = 3.25$
Поскольку $2 ≤ 3.25 ≤ 7$, используется вторая ветвь:

$Q(3.25)=2(3.25-4.5)+50$

$Q(3.25)=2(-1.25)+50$

$\boxed{Q(3.25)=47.50}$

Пример 3: $X = 10$
Поскольку $10 > 7$, используется третья ветвь:

$Q(10)=4\ln(10-5)+60$

$Q(10)=4\ln(5)+60$

$\boxed{Q(10)\approx66.44}$

Полученные результаты подтверждают правильность применения всех трёх ветвей математической модели.

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
<img width="299" height="867" alt="image" src="https://github.com/user-attachments/assets/1a168c00-6776-4b07-aa06-0486077c2947" />

[Ссылка на блок-схему 1](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7VnJcuIwEP0aV2UOSXllOYZtkqpMFiDbUbEb2xPZooQIMF8%2Fst3GNjgUoVgyNeYg1E%2FdQu5%2BPAmhGO1g%2FpOTsfeLOUAVXXXmitFRdF0zm4Z8i5BFgjRVBFzuO%2BiUAQP%2FDyCoIjr1HZgUHAVjVPjjImizMARbFDDCOZsV3UaMFj91TFxYAwY2oevos%2B8IL0Ebej3Dr8B3vfSTtVozGQlI6oxPMvGIw2Y5yOgqRpszJpJeMG8DjZKX5iWJ630yulwYh1BsE3A%2FIw3GO2HfNrW33vOo%2B6pfn2tYDXDW0pDNi9CETbmNXo9X1%2F0FtYMHu%2F%2FkNh57%2FaepONfx0SdikaYvmneAJuPCYy4LCe1maIuzaehAtEZVWpnPDWNjCWoS%2FA1CLJAaZCqYhDwRUByFuS9eovALC63X3EhnjjPHxiI1QsEXuaDIfM2PZWGxlcY5MCJTKm7IG9AWsd%2FdePVtRhmXHgmXWiMWih4JfBpFDf1A0ldXb2Em2z4LSIgu%2BEC6KW0kNuEuiA0JNrQlb%2BQXDlgAcnEykAMlwv8oVpAg892lX0YO2UF%2BlHNlY3nLqJFVXNJ8DHEyOKEUKHM5CeQjjoHLVAjgq2P32UBr5vkCBmMS02wmFaVY6nju63AiJQGRkT%2BHVDUSm9K0HDT6Wp47hL%2BfKbrRi1%2BK3l72f2Ahyv3V%2BJX4J%2F3IXy7Y8SGLCVkYlXwiOHuHr0y0M0k%2BCJ1iqgfDy2EXUeAC5rmarJPEy8lUHTVplkmarloJhrMYGtYWhbumqgfilbFBcnJKQqnUfNiNJP8RKRS9RkUkVf6H7LpRV5Ha1byM2lY3bjtxaykyO41aGiBrl48pmQahN76KrIbuwMhmCSPTnTNlpGpcWAVO1rU9cLJ0X2zuti2WzqX%2FK7vi8Xa30jzVjrS5bSpStbd9Exl7Oda%2BplmH0hBN36OImJWIbHVETg6pp1IRs1KRb6Ui7bvbYf%2Fu5oBasnIiMZsHUxNtj2piVWqy1ZHEPKWYWJWYfCsxeTiejBh161Ayou5RRmqnkJETS4K1xotTakSt0ohvpRG9s5cfx%2FrlsozZO6sae9SIenXU2EpXTioj9c%2FrW93A7usGNrl1VeNb13ral20Lb2aPfJlqFsXk61oizezfy3gs9x%2Bw0f0L%3C%2Fdiagram%3E%3C%2Fmxfile%3E)

<img width="481" height="881" alt="image" src="https://github.com/user-attachments/assets/d4cf3cb5-6f54-4581-9e89-1eaef0077256" />

[Ссылка на блок-схему 2](https://viewer.diagrams.net/?tags=%7B%7D&lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&dark=auto#R%3Cmxfile%3E%3Cdiagram%20name%3D%22%D0%A1%D1%82%D1%80%D0%B0%D0%BD%D0%B8%D1%86%D0%B0-1%22%20id%3D%22goGTumh30XNIcFfH6rBE%22%3E7VjbctowEP0az7QPYXzBQB5jLgkzaScBkjSPir3YamTLI0SAfn3XtmxjcFJCSclM4UFoj3bX8uroWCPN6obLS0Hi4Bv3gGmm7i01q6eZpmE2DfxLkFWGtG0F%2BIJ6yqkExvQXKFBX6Jx6MKs4Ss6ZpHEVdHkUgSsrGBGCL6puU86qT42JD1vA2CVsG32gngwytGO2S%2FwKqB%2FkTzZa59lISHJn9SazgHh8sQZZfc3qCs5l1guXXWBJ8fK6ZHGDV0aLiQmI5C4Bd1fD0Yq54a07uvc7d4PR%2FVyeWTVpFDSTq7wImAjrjYazCKiEcUzcZGSBS45YIEOGloFdfMcYhtEM10whU8pYlzMu0GZJnc48Ip6%2FaKY1SH%2Ba2S36XxN%2FHsl6fz39Zf5ZP%2FH3BfEolDERj5J5zqTgz%2FCeRMmDBySkLCHqhIZIOlP%2FDgtsRzwkkXJRDDWbaGd1eiFsruqkmS2GRXQ8%2BoJdP%2BlqPV07v0hap5%2B2vbS1NaxOp5UH4Kqtx9SkUdCT2EQ2Q9MpgZCwXFtNxYhL4CFIsUKXYI2054qhi5LgBWtVFktvZrbaxs08hqj95RepSwpiR7GwnpE3C9LhoheN3KbxNHiY9h%2FN4ZnaPuBt7ctthvK5cOGNXOY2kzHtWJlcyID7PCKsX6KO4PPIg2SGOlqlzzXnseL0T5BypYhA5pJX9wAsqfyRhDdsZT2ujfSWKnNqrJThwZTMmbwmT8Ac4j776Sxy%2BmYatT9DJRE%2ByDfq1KrniABGJH2prsPBF9zcRYFSYUlLIQhjwDju%2BxBfMAaBhZAgNsduyoF9RGsJ%2BbfovxOxW812NLu3l5K0a5REt6tKYhgVJTHsj1KS%2FEEHkRL7JCV%2FJREq9IZTrHxBhqbxh89KJl0qaoMPxTT2p4h90p5PpT01J5%2Fx5GIyHE%2BG3fHnOCztJnENu8Jrq21%2FlMjpBxS51jFE7shnH7uGhMc7DLVOgvSpBCk5DBmNBn6m%2Ft2JqIg5OLs6B9SK9ulAtJO%2BHFVO2q%2Bv7%2Bl251C3O9mNjp7e6LTzPraOuvU56kWN%2BX4tQbO8lcxO2uXdrtX%2FDQ%3D%3D%3C%2Fdiagram%3E%3C%2Fmxfile%3E)
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
