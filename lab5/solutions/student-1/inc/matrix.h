#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"

typedef struct s_matrix
{
	int	rows;
	int	cols;
	int	**matrix;
}t_matrix;

t_matrix	*create_matrix(int rows, int cols);
void		remove_matrix(t_matrix *A);
void		print_matrix(t_matrix *A);

t_matrix	*sum_matrix(t_matrix *A, t_matrix *B);
t_matrix	*sub_matrix(t_matrix *A, t_matrix *B);

#endif
