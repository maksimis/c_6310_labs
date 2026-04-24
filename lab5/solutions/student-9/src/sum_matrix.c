#include "matrix.h"

matrix_t *sum_matrix(matrix_t *A, matrix_t *B) {
    matrix_t *result;
    int i;
    int j;

    if (!A || !B || !A->matrix || !B->matrix)
        return NULL;
    if (A->rows != B->rows || A->columns != B->columns)
        return NULL;
    result = create_matrix(A->rows, A->columns);
    if (!result)
        return NULL;
    for (i = 0; i < A->rows; i++) {
        for (j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
    }
    return result;
}
