#include "matrix.h"

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *result;
    int i;

    if (rows <= 0 || cols <= 0)
        return NULL;
    result = (matrix_t *)malloc(sizeof(matrix_t));
    if (!result)
        return NULL;
    result->rows = rows;
    result->columns = cols;
    result->matrix = (int **)malloc(sizeof(int *) * rows);
    if (!result->matrix) {
        free(result);
        return NULL;
    }
    for (i = 0; i < rows; i++) {
        result->matrix[i] = (int *)malloc(sizeof(int) * cols);
        if (!result->matrix[i]) {
            while (--i >= 0)
                free(result->matrix[i]);
            free(result->matrix);
            free(result);
            return NULL;
        }
    }
    return result;
}
