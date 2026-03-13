/*
 * Лабораторная работа №1
 * Студент: Студент (номер: 21)
 * Вариант: 22
 * Задание: 7 (Проверка числа на простоту)
 */

#include <stdio.h>
#include <math.h>

static int is_prime(int number)
{
    if (number < 2) {
        return 0;
    }
    if (number == 2) {
        return 1;
    }
    if (number % 2 == 0) {
        return 0;
    }

    int limit = (int)sqrt((double)number);
    for (int divisor = 3; divisor <= limit; divisor += 2) {
        if (number % divisor == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int input_number = 0;

    printf("Проверка числа на простоту\n");
    printf("Введите целое число: ");
    if (scanf("%d", &input_number) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод\n");
        return 1;
    }

    if (input_number < 0) {
        fprintf(stderr, "Ошибка: число должно быть неотрицательным\n");
        return 1;
    }

    if (is_prime(input_number)) {
        printf("Число %d является простым\n", input_number);
    } else {
        printf("Число %d не является простым\n", input_number);
    }

    return 0;
}
