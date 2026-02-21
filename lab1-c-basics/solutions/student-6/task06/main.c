/*
 * Лабораторная работа №1
 * Студент: Валиев Марсель (номер: 6)
 * Вариант: 6
 * Задание: 6 (Среднее арифметическое массива)
 */

#include <stdio.h>

int main(void) {
    int n;

    printf("Compute the average of array elements.\n");
    printf("Enter the size of the array (positive integer): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: size must be a positive integer.\n");
        return 1;
    }

    double arr[n];
    double sum = 0.0;

    printf("Enter %d elements (integer or real numbers):\n", n);
    for (int i = 0; i < n; ++i) {
        printf("arr[%d] = ", i);
        if (scanf("%lf", &arr[i]) != 1) {
            fprintf(stderr, "Error: invalid number input.\n");
            return 1;
        }
        sum += arr[i];
    }

    double average = sum / n;
    printf("Arithmetic mean of array elements = %.2f\n", average);

    return 0;
}