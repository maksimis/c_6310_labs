#include "matrix.h"
#include "libft.h"

matrix_t *create_matrix(int rows, int cols)
{
    matrix_t *res;
    int i;

    if (rows <= 0 || cols <= 0)
        return (NULL);

    res = (matrix_t *)ft_calloc(1, sizeof(matrix_t));
    if (!res)
        return (NULL);

    res->rows = rows;
    res->columns = cols;

    res->matrix = (int **)ft_calloc(rows, sizeof(int *));
    if (!res->matrix)
    {
        free(res);
        return (NULL);
    }

    i = 0;
    while (i < rows)
    {
        res->matrix[i] = (int *)ft_calloc(cols, sizeof(int));
        if (!res->matrix[i])
        {
            while (i > 0)
                free(res->matrix[--i]);
            free(res->matrix);
            free(res);
            return (NULL);
        }
        i++;
    }

    return (res);
}