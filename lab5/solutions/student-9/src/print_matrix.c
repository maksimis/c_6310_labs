#include "matrix.h"

void print_matrix(matrix_t *matrix) {
    int i;
    int j;

    if (!matrix || !matrix->matrix)
        return;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->columns; j++) {
            ft_putnbr_fd(matrix->matrix[i][j], 1);
            if (j < matrix->columns - 1)
                ft_putchar_fd(' ', 1);
        }
        ft_putchar_fd('\n', 1);
    }
}
