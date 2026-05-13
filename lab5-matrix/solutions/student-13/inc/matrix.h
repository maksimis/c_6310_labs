#ifndef MATRIX_H
# define MATRIX_H

# include "../libft/inc/libft.h"

typedef struct matrix_struct
{
	int	**matrix;
	int	rows;
	int	columns;
}	matrix_t;

matrix_t	*create_matrix(int rows, int cols);
void		remove_matrix(matrix_t *a);
void		print_matrix(matrix_t *a);
matrix_t	*sum_matrix(matrix_t *a, matrix_t *b);
matrix_t	*sub_matrix(matrix_t *a, matrix_t *b);
void		fill_matrix(matrix_t *a, int start);
void		print_error(char *message);

#endif