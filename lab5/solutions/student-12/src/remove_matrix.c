#include "matrix.h"
#include <stdlib.h> // для free

void remove_matrix(matrix_t *A)
{
    int i; // счётчик для прохода по строкам

    if (!A) // проверка на NULL
        return;

    if (A->matrix) // проверяем есть ли вообще массив строк
    {
        i = 0;
        while (i < A->rows) // проходим по всем строкам
        {
            if (A->matrix[i]) // проверка частично созданной матрицы или возможных NULL внутри массива
                free(A->matrix[i]); // освобождаем каждую строку
            i++;
        }
        free(A->matrix); // освобождение массива указателей
    }

    free(A); // удаляем саму структуру
}