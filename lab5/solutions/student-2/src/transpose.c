#include "matrix.h"

matrix_t *transpose(matrix_t *a)
{
    matrix_t *result;
    int i;
    int j;

    if (!a || !a->matrix || a->rows <= 0 || a->columns <= 0)
        return (NULL);
    result = create_matrix(a->columns, a->rows);
    if (!result)
        return (NULL);
    i = 0;
    while (i < a->rows)
    {
        j = 0;
        while (j < a->columns)
        {
            result->matrix[j][i] = a->matrix[i][j];
            j++;
        }
        i++;
    }
    return (result);
}