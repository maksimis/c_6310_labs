#ifndef MATRIX_H
#define MATRIX_H

#include "libft.h"

typedef struct s_matrix
{
	int		rows;
	int		cols;
	int		**matrix;
}	matrix_t;

matrix_t *create_matrix(int rows, int cols);
void remove_matrix(matrix_t *A);
void print_matrix(matrix_t *A);
matrix_t *mult_number(matrix_t *A, int num);
matrix_t *transpose(matrix_t *A);

#endif