#include "matrix.h"

static void free_rows(int **matrix, int count)
{
    int	i;

    i = 0;
    while (i < count)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

static void init_row_zero(int *row, int cols)
{
    int j;

    j = 0;
    while (j < cols)
    {
        row[j] = 0;
        j++;
    }
}

matrix_t *create_matrix(int rows, int cols)
{
    matrix_t *a;
    int i;

    if (rows <= 0 || cols <= 0)
        return (NULL);
    a = (matrix_t *)malloc(sizeof(matrix_t));
    if (!a)
        return (NULL);
    a->rows = rows;
    a->columns = cols;
    a->matrix = (int **)malloc(sizeof(int *) * rows);
    if (!a->matrix)
    {
        free(a);
        return (NULL);
    }
    i = 0;
    while (i < rows)
    {
        a->matrix[i] = (int *)malloc(sizeof(int) * cols);
        if (!a->matrix[i])
        {
            free_rows(a->matrix, i);
            free(a);
            return (NULL);
        }
        init_row_zero(a->matrix[i], cols);
        i++;
    }
    return (a);
}