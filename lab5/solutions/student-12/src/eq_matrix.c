#include "matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B)
{
    int i;
    int j;

    if (!A || !B || !A->matrix || !B->matrix) // проверка на NULL
        return (0);

    if (A->rows != B->rows || A->columns != B->columns) // проверка размеров матриц
        return (0);

    i = 0;
    while (i < A->rows)
    {
        j = 0;
        while (j < A->columns)
        {
            if (A->matrix[i][j] != B->matrix[i][j])
                return (0);
            j++;
        }
        i++;
    }

    return (1);
}