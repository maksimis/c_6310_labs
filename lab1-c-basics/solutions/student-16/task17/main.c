/*
 * Лабораторная работа №1
 * Студент: 16
 * Вариант: 17
 * Задание: 17 (Наименьшее общее кратное двух чисел)
 */

#include <stdio.h>

static int gcd(int first, int second) {
    while (second != 0) {
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}

static int lcm(int first, int second) {
    return first / gcd(first, second) * second;
}

int main(void) {
    int first, second;

    printf("Введите два натуральных числа: ");
    if (scanf("%d %d", &first, &second) != 2) {
        fprintf(stderr, "Ошибка: некорректный ввод\n");
        return 1;
    }

    if (first <= 0 || second <= 0) {
        fprintf(stderr, "Ошибка: числа должны быть натуральными (больше 0)\n");
        return 1;
    }

    printf("НОК(%d, %d) = %d\n", first, second, lcm(first, second));

    return 0;
}
