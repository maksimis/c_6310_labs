/*
 * Лабораторная работа №1
 * Студент: Валеев Камил (номер: 5)
 * Вариант: 6
 * Задание: 6 (Среднее арифметическое массива)
 */

#include <stdio.h>

#define MAX_SIZE 10

int main(void) {
    int n;
    double arr[MAX_SIZE];
    double sum = 0.0;
    double average;
    printf("Введите количество элементов массива (не более %d): ", MAX_SIZE);
    
    if (scanf("%d", &n) != 1) {
        printf("Ошибка: необходимо ввести целое число.\n");
        return 1;
    }
    
    if (n <= 0) {
        printf("Ошибка: количество элементов должно быть положительным.\n");
        return 1;
    }
    
    if (n > MAX_SIZE) {
        printf("Ошибка: максимальное количество элементов - %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Ошибка: необходимо ввести число.\n");
            return 1;
        }
        sum += arr[i];
    }

    average = sum / n;
    
    printf("\n--- Результат ---\n");
    printf("Массив: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    printf("Сумма элементов: %.2f\n", sum);
    printf("Количество элементов: %d\n", n);
    printf("Среднее арифметическое: %.2f\n", average);
    
    return 0;
}