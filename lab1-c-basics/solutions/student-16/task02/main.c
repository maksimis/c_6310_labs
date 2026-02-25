/*
 * Лабораторная работа №1
 * Студент: 16
 * Вариант: 17
 * Задание: 2 (Нахождение наибольшего числа в массиве)
 */

#include <stdio.h>

#define MAX_SIZE 100

static int find_max(const int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
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

    printf("Наибольший элемент: %d\n", find_max(array, size));

    return 0;
}
