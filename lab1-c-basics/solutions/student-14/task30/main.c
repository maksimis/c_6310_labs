/*
 * Лабораторная работа №1
 * Студент: Зиатдинова Дина (номер: 14)
 * Вариант: 15
 * Задание: 30 (Сумма элементов каждого столбца в матрице)
 */

#include <stdio.h>

int main(void) {
    int rows, columns;
    int const max_size = 10;

    printf("Укажите размер матрицы. Максимально допустимый размер %d*%d\nВведите количество строк: ", max_size, max_size);
    int res1 = scanf("%d", &rows);
    if (res1 != 1) {
        printf("Ошибка! Значения размерности матрицы должны быть числами\n");
        return 1;
    }

    printf("Введите количество столбцов: ");
    int res2 = scanf("%d", &columns);
    if (res2 != 1) {
        printf("Ошибка! Значения размерности матрицы должны быть числами\n");
        return 1;
    }

    if (rows <= 0 || columns <= 0) {
        printf("Ошибка! Значения размерности матрицы должны быть положительными числами\n");
        return 1;
    }
    if (rows > max_size || columns > max_size) {
        printf("Ошибка! Максимально допустимый размер матрицы %d*%d\n", max_size, max_size);
        return 1;
    }

    int matrix[rows][columns];
    int row_index;
    int column_index;

    printf("Введите элементы матрицы (%d строки по %d чисел):\n", rows, columns);
    for (row_index = 0; row_index < rows; row_index++) {
        for (column_index = 0; column_index < columns; column_index++) {
            int result = scanf("%d", &matrix[row_index][column_index]);
            if (result != 1) {
                printf("Ошибка! Значения матрицы должны быть числами");
                return 1;
            }
        }
    }

    printf("\nВведённая матрица:\n");
    for (row_index = 0; row_index < rows; row_index++) {
        for (column_index = 0; column_index < columns; column_index++) {
            printf("%d ", matrix[row_index][column_index]);
        }
        printf("\n");
    }

    for (column_index = 0; column_index < columns; column_index++) {
        int sum = 0;
        for (row_index = 0; row_index < rows; row_index++) {
            sum += matrix[row_index][column_index];
        }
        printf("Сумма столбца %d: %d\n", column_index, sum);
    }

    return 0;
};