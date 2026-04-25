#ifndef MATRIX_H
# define MATRIX_H

# include "libft.h"

typedef struct s_matrix
{
	int		rows;
	int		cols;
	int		**data;
}	t_matrix;

t_matrix	*create_matrix(int rows, int cols);
void		remove_matrix(t_matrix *A);
void		print_matrix(t_matrix *A);

t_matrix	*mult_number(t_matrix *A, int num);
t_matrix	*transpose(t_matrix *A);

#endif