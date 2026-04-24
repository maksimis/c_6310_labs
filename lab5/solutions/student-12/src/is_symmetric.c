#include "matrix.h"

int is_symmetric(matrix_t *A)
{
    int i;
    int j;

    if (!A || !A->matrix)
        return (0);

    if (A->rows != A->columns)
        return (0);

    i = 0;
    while (i < A->rows)
    {
        j = 0;
        while (j < A->columns)
        {
            if (A->matrix[i][j] != A->matrix[j][i])
                return (0);
            j++;
        }
        i++;
    }

    return (1);
}