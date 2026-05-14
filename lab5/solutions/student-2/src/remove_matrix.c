#include "matrix.h"

void remove_matrix(matrix_t *a)
{
    int	i;

    if (!a)
        return ;
    if (a->matrix)
    {
        i = 0;
        while (i < a->rows)
        {
            free(a->matrix[i]);
            i++;
        }
        free(a->matrix);
    }
    free(a);
}