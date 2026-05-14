#include "matrix.h"

matrix_t *mult_number(matrix_t *a, int num)
{
    matrix_t *result;
    int i;
    int j;

    if (!a || !a->matrix || a->rows <= 0 || a->columns <= 0)
        return (NULL);
    result = create_matrix(a->rows, a->columns);
    if (!result)
        return (NULL);
    i = 0;
    while (i < a->rows)
    {
        j = 0;
        while (j < a->columns)
        {
            result->matrix[i][j] = a->matrix[i][j] * num;
            j++;
        }
        i++;
    }
    return (result);
}