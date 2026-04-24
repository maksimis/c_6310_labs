#include "matrix.h"

void remove_matrix(matrix_t *matrix) {
    int i;

    if (!matrix)
        return;
    if (matrix->matrix) {
        for (i = 0; i < matrix->rows; i++) {
            if (matrix->matrix[i])
                free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
    free(matrix);
}
