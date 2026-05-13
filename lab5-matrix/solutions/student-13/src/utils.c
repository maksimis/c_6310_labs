#include "matrix.h"

void	print_error(char *message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
}

void	fill_matrix(matrix_t *a, int start)
{
	int	i;
	int	j;
	int	value;

	if (!a || !a->matrix)
		return ;
	value = start;
	i = 0;
	while (i < a->rows)
	{
		j = 0;
		while (j < a->columns)
		{
			a->matrix[i][j] = value;
			value++;
			j++;
		}
		i++;
	}
}