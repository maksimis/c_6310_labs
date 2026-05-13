#include "matrix.h"

void	print_matrix(t_matrix *A)
{
	int	i;
	int	j;

	if (!A)
	{
		ft_putstr_fd("NULL matrix\n", 2);
		return ;
	}
	i = 0;
	while (i < A->rows)
	{
		j = 0;
		while (j < A->cols)
		{
			ft_putnbr_fd(A->data[i][j], 1);
			if (j < A->cols - 1)
				ft_putchar_fd(' ', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}