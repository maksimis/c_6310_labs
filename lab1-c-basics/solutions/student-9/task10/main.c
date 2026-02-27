/*
 * Лабораторная работа №1
 * Студент: Гимадиев Адель (номер: 9)
 * Вариант: 10
 * Задание: 10 (Перевод десятичного числа в двоичное)
*/

#include <stdio.h>

int main(void) {
    int number;
    int binary_digits[64];
    int index = 0;

    printf("Введите неотрицательное целое число: ");
    if (scanf("%d", &number) != 1) {
        printf("Ошибка: необходимо ввести целое число.\n");
        return 1;
    }

    if (number < 0) {
        printf("Ошибка: число должно быть неотрицательным.\n");
        return 1;
    }

    if (number == 0) {
        printf("Двоичное представление: 0\n");
        return 0;
    }

    int temp = number;
    while (temp > 0) {
        binary_digits[index] = temp % 2;
        temp /= 2;
        index++;
    }


    printf("Двоичное представление числа %d: ", number);
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_digits[i]);
    }
    printf("\n");

    return 0;
}