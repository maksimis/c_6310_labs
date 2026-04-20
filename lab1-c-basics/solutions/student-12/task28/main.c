/*
Лабораторная работа №1
Студент: Загеева Ксения (номер: 12)
Вариант: 13
Задание: 28 (Корни квадратного уравнения с помощью функции)
*/

#include <stdio.h> // для printf и scanf
#include <ctype.h> // для isspace (проверять пробелы, табуляции, переводы строк)
#include <math.h> // для sqrt

const double TWO = 2.0; // глобальные константы, чтобы без магических чисел 
const double FOUR = 4.0; // глобальные константы, чтобы без магических чисел 

/* функция для считывания входных данных */
int read_integer(const char *prompt, int *number) {
    char buffer[100]; 

    printf("%s", prompt); // %s — для строк

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Ошибка ввода: ввод не получен\n");
        return 1;
    }

    /* проверка на пустой ввод */
    int only_spaces = 1;
    for (size_t i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (!isspace((unsigned char)buffer[i])) {
            only_spaces = 0;
            break;
        }
    }

    if (only_spaces) {
        printf("Ошибка: пустой ввод\n");
        return 1;
    }

    /* проверка, что введено одно целое число */
    char extra;
    if (sscanf(buffer, " %d %c", number, &extra) != 1) {
        printf("Ошибка: некорректный ввод, введите одно целое число\n");
        return 1;
    }

    return 0;
}

/* функция для вычисления корней */
void solve_quadratic(int coefficientA, int coefficientB, int coefficientC) { // void — тип функции (функция не возвращает значение)
    double discriminant = (double)coefficientB * coefficientB - FOUR * coefficientA * coefficientC; // double — тип переменной с плавающей точкой

    if (discriminant < 0) {
        printf("Действительных корней нет\n");
        return;
    }

    if (discriminant == 0) {
        double root = -coefficientB / (TWO * coefficientA);
        printf("Один корень: x = %.5f\n", root); // "%.5f" — формат: число с плавающей точкой с 5 знаками после запятой.
        return;
    }

    double sqrt_discriminant = sqrt(discriminant);
    double root1 = (-coefficientB + sqrt_discriminant) / (TWO * coefficientA);
    double root2 = (-coefficientB - sqrt_discriminant) / (TWO * coefficientA);

    printf("Два корня:\n");
    printf("x1 = %.5f\n", root1);
    printf("x2 = %.5f\n", root2);
}

int main(void) {
    int coefficientA, coefficientB, coefficientC;

    printf("Общий вид уравнения: y = a*x^2 + b*x + c\n");

    if (read_integer("Введите коэффициент a: ", &coefficientA) != 0) {
        return 1;
    }

    if (coefficientA == 0) {
        printf("Ошибка: коэффициент a не должен быть равен 0\n");
        return 1;
    }

    if (read_integer("Введите коэффициент b: ", &coefficientB) != 0) {
        return 1;
    }

    if (read_integer("Введите коэффициент c: ", &coefficientC) != 0) {
        return 1;
    }

    solve_quadratic(coefficientA, coefficientB, coefficientC);

    return 0;
}

/* Тесты:
1. положительное
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: 1
Введите коэффициент b: 10
Введите коэффициент c: 1
Два корня:
x1 = -0.10102
x2 = -9.89898
2. 0
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: 0
Ошибка: коэффициент a не должен быть равен 0
3. отрицательное
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: -1
Введите коэффициент b: -10
Введите коэффициент c: -1
Два корня:
x1 = -9.89898
x2 = -0.10102
4. строка 
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: qwerty
Ошибка: некорректный ввод, введите одно целое число
5. число+строка
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: 1q
Ошибка: некорректный ввод, введите одно целое число
6. набор чисел 
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: 1 1 1
Ошибка: некорректный ввод, введите одно целое число
7. пустая строка
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a:
Ошибка: пустой ввод
8. строка из пробелов
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a:                     
Ошибка: пустой ввод
9. дробные
Общий вид уравнения: y = a*x^2 + b*x + c
Введите коэффициент a: 4.5
Ошибка: некорректный ввод, введите одно целое число
*/