#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"
# include <stdlib.h>

typedef struct matrix_struct
{
    int **matrix;
    int rows;
    int columns;
}   matrix_t;

matrix_t    *create_matrix(int rows, int cols);
void        remove_matrix(matrix_t *a);
void        print_matrix(matrix_t *a);
matrix_t    *mult_number(matrix_t *a, int num);
matrix_t    *transpose(matrix_t *a);

#endif