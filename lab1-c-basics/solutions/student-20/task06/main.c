/*
 * Лабораторная работа №1
 * Студент: Мартынова Милена (номер: 20)
 * Вариант: 21
 * Задание: 6 (Среднее арифметическое массива)
 */

#include <stdio.h>

#define MAX_SIZE 100

static double calculate_average(const int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double)sum / size;
}

int main(void) {
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод\n");
        return 1;
    }

    if (size < 1 || size > MAX_SIZE) {
        fprintf(stderr, "Ошибка: размер массива должен быть от 1 до %d\n", MAX_SIZE);
        return 1;
    }

    printf("Введите %d элемент(ов) массива: ", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Ошибка: некорректный ввод элемента %d\n", i + 1);
            return 1;
        }
    }

    printf("Среднее арифметическое: %.4f\n", calculate_average(array, size));
    return 0;
}
